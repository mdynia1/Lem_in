/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_check_speceficators.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 20:54:53 by mdynia            #+#    #+#             */
/*   Updated: 2018/03/04 20:54:56 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*to_check_specificator(char *format, va_list argm)
{
	int		n;

	n = 0;
	if (ft_strchr(format, 't') != NULL || ft_strchr(format, 'z') != NULL
		|| ft_strchr(format, 'j') != NULL || ft_strchr(format, 'l') != NULL)
		return (ft_itoa_long(va_arg(argm, long long)));
	while (*format)
	{
		n += *format == 'h' ? 1 : 0;
		format++;
	}
	if (n != 0)
	{
		if (n % 2 != 0)
			return (ft_itoa((short)va_arg(argm, int)));
		else
			return (ft_itoa((char)va_arg(argm, int)));
	}
	return (ft_itoa(va_arg(argm, int)));
}

char	*to_check_specificator_unsigned(char *format, va_list ar)
{
	int		n;

	n = 0;
	if (ft_strchr(format, 't') != NULL || ft_strchr(format, 'z') != NULL
		|| ft_strchr(format, 'j') != NULL || ft_strchr(format, 'l') != NULL)
		return (ft_itoa_unsigned(va_arg(ar, unsigned long long)));
	while (*format)
	{
		n += *format == 'h' ? 1 : 0;
		format++;
	}
	if (n != 0)
	{
		if (n % 2 != 0)
			return (ft_itoa_unsigned((unsigned short)va_arg(ar, unsigned int)));
		else
			return (ft_itoa_unsigned((unsigned char)va_arg(ar, unsigned int)));
	}
	return (ft_itoa_unsigned(va_arg(ar, unsigned int)));
}

char	*to_check_specificator_hex(char *format, va_list argm, int x)
{
	int		n;

	n = 0;
	if (ft_strchr(format, 't') != NULL || ft_strchr(format, 'z') != NULL ||
		ft_strchr(format, 'j') != NULL || ft_strchr(format, 'l') != NULL ||
			x == 3)
		return (to_hex(va_arg(argm, unsigned long long), x));
	while (*format)
	{
		n += *format == 'h' ? 1 : 0;
		format++;
	}
	if (n != 0)
	{
		if (n % 2 != 0)
			return (to_hex((unsigned short)va_arg(argm, unsigned int), x));
		else
			return (to_hex((unsigned char)va_arg(argm, unsigned int), x));
	}
	return (to_hex(va_arg(argm, unsigned int), x));
}

char	*to_check_specificator_octal(char *format, va_list argm)
{
	int		n;

	n = 0;
	if (ft_strchr(format, 't') != NULL || ft_strchr(format, 'z') != NULL ||
		ft_strchr(format, 'j') != NULL || ft_strchr(format, 'l') != NULL)
		return (to_octal(va_arg(argm, unsigned long long)));
	while (*format)
	{
		n += *format == 'h' ? 1 : 0;
		format++;
	}
	if (n != 0)
	{
		if (n % 2 != 0)
			return (to_octal((unsigned short)va_arg(argm, unsigned int)));
		else
			return (to_octal((unsigned char)va_arg(argm, unsigned int)));
	}
	return (to_octal(va_arg(argm, unsigned int)));
}
