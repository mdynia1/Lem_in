/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:56:06 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/03 15:08:55 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	l;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		l = 0;
		k = i;
		while (haystack[k] == needle[l])
		{
			k++;
			l++;
			if (needle[l] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
