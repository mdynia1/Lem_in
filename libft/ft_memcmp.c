/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:45:13 by mdynia            #+#    #+#             */
/*   Updated: 2017/11/20 21:32:12 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;

	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (i < n)
	{
		if (d[i] != s[i])
		{
			return (d[i] - s[i]);
		}
		i++;
	}
	return (0);
}
