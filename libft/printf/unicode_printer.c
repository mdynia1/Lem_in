/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:01:03 by mdynia            #+#    #+#             */
/*   Updated: 2018/03/16 19:01:04 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			unicode_print_char(va_list argm)
{
	wchar_t	z;
	int		i;

	i = 0;
	z = va_arg(argm, wchar_t);
	i = ft_putwchar(z);
	return (i);
}

int			unicode_null(int flag, int width, int precision)
{
	char	*to_print;

	to_print = ft_strdup("(null)");
	to_put_string_and_char(flag, width, precision, &to_print);
	return (ft_putstr_f(to_print));
}

int			unicode_flag_dealer(int flag, int width, int ws_length)
{
	int		s_or_z;
	char	*to_join;
	int		counter;

	counter = 0;
	s_or_z = (flag == ZERO && (width > ws_length)) ? '0' : ' ';
	if (width > ws_length)
	{
		to_join = ft_strnew(width - ws_length);
		to_join = ft_memset(to_join, s_or_z, (width - ws_length));
		counter = ft_putstr_f(to_join);
	}
	return (counter);
}

int			unicode_precision(int precision, wchar_t *f, int *l)
{
	int		ws_length;
	int		k;

	k = 0;
	ws_length = 0;
	while (precision != -1 && ((precision == 0 && f[k] != '\0') ||
			(precision > 0 && ws_length < precision)))
	{
		if (precision > 0 && ft_ws_len(f[k]) > precision - ws_length)
			break ;
		ws_length += ft_ws_len(f[k]);
		k++;
	}
	*l = k;
	return (ws_length);
}

int			unicode_print(va_list argm, int flag, int width, int precision)
{
	wchar_t *f;
	int		ws_length;
	int		l;

	l = 0;
	f = va_arg(argm, wchar_t *);
	ws_length = f == NULL ? unicode_null(flag, width, precision) : 0;
	if (ws_length == 0)
	{
		ws_length = unicode_precision(precision, f, &l);
		if (width > ws_length && flag != MINUS && flag != MINUS + ZERO)
			ws_length += unicode_flag_dealer(flag, width, ws_length);
		while (l >= 0 && l--)
		{
			ft_putwchar(*f);
			f++;
		}
		if (width > ws_length && (flag == MINUS || flag == MINUS + ZERO))
			ws_length += unicode_flag_dealer(flag, width, ws_length);
	}
	return (ws_length);
}
