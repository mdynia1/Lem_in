/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:49:05 by mdynia            #+#    #+#             */
/*   Updated: 2017/11/26 17:59:22 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	if (s == NULL)
	{
		return (NULL);
	}
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (len > i && s[start] != '\0')
	{
		c[i] = s[start + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
