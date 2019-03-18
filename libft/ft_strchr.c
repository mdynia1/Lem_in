/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 22:18:27 by mdynia            #+#    #+#             */
/*   Updated: 2017/11/21 22:33:12 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	l;

	l = 0;
	i = ft_strlen((char *)s);
	while (l < i || s[l] != '\0')
	{
		if (s[l] == c)
			return ((char*)&s[l]);
		l++;
	}
	if (s[l] == c)
		return ((char*)&s[l]);
	else
		return (NULL);
}
