/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort_types_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:51:03 by mdynia            #+#    #+#             */
/*   Updated: 2018/03/16 19:51:04 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*char_types(char current_type, int *precision, va_list argm)
{
	char	*to_print;

	if (current_type == 's')
	{
		to_print = va_arg(argm, char *);
		to_print = to_print == NULL || to_print == 0 ? ft_strdup("(null)")
													: ft_strdup(to_print);
	}
	if (current_type == 'R')
		to_print = ft_strdup("R");
	if (current_type == '%' || current_type == 'Z')
		to_print = current_type == 'Z' ? ft_strdup("Z") : ft_strdup("%");
	if (current_type == 'f' || current_type == 'F')
		to_print = ft_itoa_double((va_arg(argm, double)), *precision);
	*precision = current_type == 's' ? *precision : 0;
	return (to_print);
}

int		all_for_char(va_list argm, int flag, int width)
{
	char	*to_print;
	int		current_count;
	char	c;

	current_count = 0;
	c = (char)va_arg(argm, unsigned int);
	if (c == '\0')
	{
		to_print = ft_strdup("*");
		to_put_string_and_char(flag, width, 0, &to_print);
		while (to_print[current_count])
		{
			if (to_print[current_count] == '*')
				write(1, "\0", 1);
			else
				write(1, &to_print[current_count], 1);
			current_count++;
		}
		return (current_count);
	}
	to_print = ft_strdup(&c);
	to_put_string_and_char(flag, width, 0, &to_print);
	return (ft_putstr_f(to_print));
}

char	*numb_types_helper(int *flag, char c_type, va_list argm, char *f)
{
	int		x;
	char	*to_print;

	x = c_type == 'X' ? 1 : 2;
	x = c_type == 'p' ? 3 : x;
	to_print = to_check_specificator_hex(f, argm, x);
	*flag += x * 49;
	return (to_print);
}

char	*numb_types(char c_type, va_list argm, char *format, int *flag)
{
	char	*to_print;

	if (c_type == 'd' || c_type == 'i' || c_type == 'D')
	{
		to_print = c_type == 'D' ? (ft_itoa_long(va_arg(argm, long long)))
								: to_check_specificator(format, argm);
		*flag += *to_print == '-' ? NEGATIVE : 0;
	}
	else
	{
		if (c_type == 'u' || c_type == 'U')
			to_print = c_type == 'U' ?
				ft_itoa_unsigned(va_arg(argm, unsigned long long))
				: to_check_specificator_unsigned(format, argm);
		if (c_type == 'o' || c_type == 'O')
			to_print = c_type == 'O' ?
				to_octal(va_arg(argm, unsigned long long))
				: to_check_specificator_octal(format, argm);
		if (c_type == 'x' || c_type == 'X' || c_type == 'p')
			to_print = numb_types_helper(flag, c_type, argm, format);
	}
	return (to_print);
}
