/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 20:34:43 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/03 20:34:45 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*m;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	m = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (m == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		m[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		m[j++] = s2[i];
		i++;
	}
	m[j] = '\0';
	return (m);
}
