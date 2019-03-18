/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:36:02 by mdynia            #+#    #+#             */
/*   Updated: 2018/02/15 18:37:24 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_len_unsigned(unsigned long long int nb)
{
	int		n;

	n = 0;
	if (nb > 9)
		n += ft_len_unsigned(nb / 10);
	return (++n);
}

char	*ft_itoa_unsigned(unsigned long long int n)
{
	int		i;
	char	*str;

	i = ft_len_unsigned(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = (n % 10 + '0');
		n = n / 10;
	}
	return (str);
}
