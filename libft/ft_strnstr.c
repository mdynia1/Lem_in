/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:30:27 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/03 15:09:44 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)&haystack[i - j]);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i - j]);
			j++;
		}
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (0);
}
