/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:42:46 by mdynia            #+#    #+#             */
/*   Updated: 2017/11/29 21:01:02 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_ch_in_nb(int nb)
{
	int		l;

	if (!(l = 0) && nb == -2147483648 && (l += 2) != -1)
		nb = 147483648;
	if (nb < 0 && l++ != -1)
		nb *= -1;
	if (nb > 9)
		l += ft_ch_in_nb(nb / 10);
	return (++l);
}

char		*ft_itoa(int n)
{
	int		k;
	char	*str;

	k = ft_ch_in_nb(n);
	if (!(str = ft_strnew(k)))
		return (NULL);
	if (n == -2147483648 && (str[1] = '2'))
		n = -147483648;
	if (n < 0 && (str[0] = '-'))
		n *= -1;
	while (k-- && str[k] != '-' && str[k] != '2')
	{
		str[k] = (n % 10 + '0');
		n /= 10;
	}
	return (str);
}
