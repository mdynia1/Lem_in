/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:06:45 by mdynia            #+#    #+#             */
/*   Updated: 2018/03/04 17:06:51 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		init_wchar(char *p, wchar_t c, int mode)
{
	if (mode == 2)
	{
		p[0] = (((c & 0x07c0) >> 6) + 0xC0);
		p[1] = (((c & 0x003F)) + 0x80);
	}
	if (mode == 3)
	{
		p[0] = (((c & 0xF000) >> 12) + 0xE0);
		p[1] = (((c & 0x0FC0) >> 6) + 0x80);
		p[2] = (((c & 0x003F)) + 0x80);
	}
	if (mode == 4)
	{
		p[0] = (((c & 0x1C0000) >> 18) + 0xF0);
		p[1] = (((c & 0x03F000) >> 12) + 0x80);
		p[2] = (((c & 0x0FC0) >> 6) + 0x80);
		p[3] = (((c & 0x003F)) + 0x80);
	}
}

void		ft_putnchar(char *f, int size)
{
	int		i;

	i = 0;
	while (i != size)
	{
		write(1, &f[i], 1);
		i++;
	}
}

int			ft_print_w(char *f, unsigned int e, wchar_t c)
{
	if (e > 255 && e < 0x07FF)
	{
		init_wchar(f, c, 2);
		ft_putnchar(f, 2);
		ft_strdel(&f);
		return (2);
	}
	else if (e < 0xFFFF)
	{
		init_wchar(f, c, 3);
		ft_putnchar(f, 3);
		ft_strdel(&f);
		return (3);
	}
	else
	{
		init_wchar(f, c, 4);
		ft_putnchar(f, 4);
		ft_strdel(&f);
		return (4);
	}
}

int			ft_putwchar(wchar_t c)
{
	char			*str;
	unsigned int	e;

	e = (unsigned int)c;
	if (c >= 0 && c <= 255)
	{
		ft_putchar(c);
		return (1);
	}
	else
	{
		str = ft_strnew(4);
		return (ft_print_w(str, e, c));
	}
}

int			ft_ws_len(wchar_t c)
{
	unsigned int	e;

	e = (unsigned int)c;
	if (c >= 0 && c <= 255)
		return (1);
	if (e > 255 && e < 0x07FF)
		return (2);
	else if (e < 0xFFFF)
		return (3);
	else
		return (4);
}
