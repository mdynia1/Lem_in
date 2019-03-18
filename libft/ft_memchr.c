/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:40:15 by mdynia            #+#    #+#             */
/*   Updated: 2017/11/14 22:55:17 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	k;

	i = 0;
	k = (unsigned char)c;
	t = (unsigned char *)s;
	while (i < n)
	{
		if (t[i] == k)
		{
			return (t + i);
		}
		else
			i++;
	}
	return (NULL);
}
