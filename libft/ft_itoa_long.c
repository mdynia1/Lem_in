/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:58:58 by mdynia            #+#    #+#             */
/*   Updated: 2018/02/04 16:59:00 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_len_long(long long int nb)
{
	int		l;

	if (!(l = 0) && nb == LONG_MIN && (l += 2) != -1)
		nb = 223372036854775808;
	if (nb < 0 && l++ != -1)
		nb *= -1;
	if (nb > 9)
		l += ft_len_long(nb / 10);
	return (++l);
}

char		*ft_itoa_long(long long int n)
{
	int		l;
	char	*str;

	l = ft_len_long(n);
	if (!(str = ft_strnew(l)))
		return (NULL);
	if (n <= LONG_MIN && (str[1] = '9'))
		n = -223372036854775808;
	if (n < 0 && (str[0] = '-'))
		n *= -1;
	while (l-- && str[l] != '-' && str[l] != '9')
	{
		str[l] = (n % 10 + '0');
		n /= 10;
	}
	return (str);
}
