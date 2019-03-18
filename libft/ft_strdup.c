/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:47:09 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/03 15:20:43 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	l;
	char	*dup;

	i = ft_strlen(s1);
	dup = (char*)malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	l = 0;
	while (l < i)
	{
		dup[l] = s1[l];
		l++;
	}
	dup[l] = '\0';
	return (dup);
}
