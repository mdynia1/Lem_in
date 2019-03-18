/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_main_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:13:30 by mdynia            #+#    #+#             */
/*   Updated: 2018/03/16 20:13:37 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		all_flags_checker(char c_type, int *width, char *format)
{
	int		flag;
	int		minus;

	flag = 0;
	minus = *width < 0 ? MINUS : 0;
	*width = (*width < 0) ? (*width * -1) : *width;
	if (SIGN(c_type) || c_type == 'S' || c_type == 'c' || c_type == 'C')
		flag = flag_check_for_char(format, 0, 0, 0);
	if (LIST_NUMBERS(c_type))
	{
		if (c_type == 'd' || c_type == 'i' || c_type == 'D')
			flag = flag_check(format, 0, 0);
		else
		{
			flag = flag_check_unsigned(format, 0, 0);
			flag += c_type == 'p' && flag < 16 ? 16 : 0;
		}
	}
	flag += minus == 8 && (flag <= 8 || flag == 16 || flag == 17) ? 8 : 0;
	return (flag);
}

int		main_sorter(char *format, va_list argm, char type, int width)
{
	int		flag;
	int		precision;
	char	*to_print;

	precision = 0;
	width_check(format, &width, &precision, argm);
	flag = all_flags_checker(type, &width, format);
	if (type == 'S' || (type == 's' && (ft_strchr(format, 'l') != NULL)))
		return (unicode_print(argm, flag, width, precision));
	else if (type == 'C' || (type == 'c' && ft_strchr(format, 'l') != NULL))
		return (unicode_print_char(argm));
	else if (type == 'c')
		return (all_for_char(argm, flag, width));
	else if (SIGN(type))
	{
		to_print = char_types(type, &precision, argm);
		to_put_string_and_char(flag, width, precision, &to_print);
	}
	else
	{
		to_print = numb_types(type, argm, format, &flag);
		to_sort_width_and_prec(flag, width, precision, &to_print);
	}
	return (ft_putstr_f(to_print));
}

int		to_sort_types(char **str, va_list argm, int current_count)
{
	char	*to_save;
	char	*format;
	char	current_type;
	int		i;

	i = 0;
	to_save = *str;
	while (**str && *str && !(TYPES_LIST(*(*str))))
	{
		i++;
		(*str)++;
	}
	if (**str == '\0')
	{
		*str = to_save;
		while (FLAGS(**str) || SPEC(**str) || **str == '.' || ft_isdigit(**str))
			(*str)++;
		return (0);
	}
	current_type = *(*str);
	format = ft_strnew((size_t)i);
	ft_memcpy(format, to_save, i);
	current_count = main_sorter(format, argm, current_type, 0);
	ft_strdel(&format);
	return (current_count);
}
