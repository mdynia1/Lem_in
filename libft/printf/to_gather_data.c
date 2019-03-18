/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_gather_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:12:15 by mdynia            #+#    #+#             */
/*   Updated: 2018/02/28 17:12:47 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		flag_check_for_char(char *format, int zero, int minus, int i)
{
	while (format[i] != '\0')
	{
		if (format[i] == '0')
			if (i == 0 || (!ft_isdigit(format[i - 1]) && format[i - 1] != '.'))
				zero = 1;
		i++;
	}
	minus = ft_strchr(format, '-') ? 8 : 0;
	return (zero + minus);
}

int		flag_check(char *format, int i, int zero)
{
	int	minus;
	int	space;
	int	plus;

	while (format[i] != '\0')
	{
		if (format[i] == '0')
		{
			if (i == 0 || (!ft_isdigit(format[i - 1]) && format[i - 1] != '.'))
			{
				zero = ft_strchr(format, '.') ? 0 : 1;
				zero = zero == 0 && ft_strchr(format, 'M') != NULL ? 1 : zero;
			}
		}
		i++;
	}
	minus = ft_strchr(format, '-') ? 8 : 0;
	space = ft_strchr(format, ' ') ? 2 : 0;
	plus = ft_strchr(format, '+') ? 4 : 0;
	return (plus + space + zero + minus);
}

int		flag_check_unsigned(char *format, int i, int zero)
{
	int	minus;
	int	hashtag;

	while (format[i] != '\0')
	{
		if (format[i] == '0')
		{
			if (i == 0 || (!ft_isdigit(format[i - 1]) && format[i - 1] != '.'))
			{
				zero = ft_strchr(format, '.') ? 0 : 1;
				zero = zero == 0 && ft_strchr(format, 'M') != NULL ? 1 : zero;
			}
		}
		i++;
	}
	minus = ft_strchr(format, '-') ? 8 : 0;
	hashtag = ft_strchr(format, '#') ? 16 : 0;
	return (hashtag + zero + minus);
}

void	precision_check(char **format, int *precision, va_list argm)
{
	if (**format == '*' && (*precision = (va_arg(argm, int))))
	{
		if (*precision <= 0)
			*precision = *precision == 0 ? -1 : 0;
		**format = *precision == 0 ? 'M' : **format;
	}
	else
		*precision = (ft_isdigit(**format) && **format != '0') ?
					ft_atoi(*format) : -1;
	while (**format && (ft_isdigit(**format) || **format == '*'))
		(*format)++;
}

void	width_check(char *format, int *width, int *precision, va_list argm)
{
	while (*format)
	{
		while (*format && ((!ft_isdigit(*format) || *format == '0') &&
				*format != '*' && *format != '.'))
			format++;
		if (*format == '.' && format++)
			precision_check(&format, precision, argm);
		else if (ft_isdigit(*format) || *format == '*')
		{
			if (*format == '*' && format++)
				*width = (va_arg(argm, int));
			else
			{
				*width = ft_atoi(format);
				while (*format && ft_isdigit(*format))
					format++;
			}
		}
	}
}
