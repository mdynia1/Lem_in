/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:41:54 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/03 15:04:35 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;
	size_t	dlen;
	size_t	slen;

	l = 0;
	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize < dlen + 1)
		return (slen + dstsize);
	while (dst[i] != '\0' && i < dstsize - 1)
		i++;
	while (dstsize - 1 > i && src[l] != '\0')
	{
		dst[i] = src[l];
		i++;
		l++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}
