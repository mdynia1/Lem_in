/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 21:06:21 by mdynia            #+#    #+#             */
/*   Updated: 2018/03/04 21:06:25 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		to_convert_hex(int s, int x)
{
	int					c;
	char				*hex_lower;
	char				*hex_upper;
	char				*hex;

	hex_lower = "abcdef";
	hex_upper = "ABCDEF";
	hex = x == 1 ? hex_upper : hex_lower;
	c = (s >= 0 && s <= 9) ? s + '0' : hex[s - 10];
	return (c);
}

char	*to_hex(unsigned long long k, int x)
{
	char				*to_print;
	unsigned long long	mem;
	unsigned long long	tmp;
	int					s;

	s = 0;
	mem = 0;
	tmp = k;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		s++;
	}
	s = k == 0 ? 1 : s;
	to_print = ft_strnew(s + 1);
	to_print[s + 1] = '\0';
	to_print[0] = k == 0 ? '0' : to_print[0];
	while (k != 0)
	{
		s--;
		mem = k % 16;
		k = k / 16;
		to_print[s] = to_convert_hex(mem, x);
	}
	return (to_print);
}

char	*to_octal(unsigned long long k)
{
	char				*to_print;
	unsigned long long	mem;
	unsigned long long	tmp;
	int					s;

	s = 0;
	mem = 0;
	tmp = k;
	while (tmp != 0)
	{
		tmp = tmp / 8;
		s++;
	}
	s += k == 0 ? 1 : 0;
	to_print = ft_strnew(s + 1);
	to_print[s + 1] = '\0';
	to_print[0] = k == 0 ? '0' : to_print[0];
	while (k != 0)
	{
		s--;
		mem = k % 8;
		k = k / 8;
		to_print[s] = mem + '0';
	}
	return (to_print);
}
