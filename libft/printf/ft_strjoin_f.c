/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 23:16:57 by mdynia            #+#    #+#             */
/*   Updated: 2018/02/06 23:17:22 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_f(char **s1, char **s2)
{
	char	*m;
	int		j;
	char	*temp1;
	char	*temp2;

	temp1 = *s1;
	temp2 = *s2;
	if (*s1 == NULL || *s2 == NULL)
		return (NULL);
	m = ft_memalloc(ft_strlen(*s1) + ft_strlen(*s2) + 1);
	if (m == NULL)
		return (NULL);
	j = 0;
	while (**s1 != '\0')
		m[j++] = *(*s1)++;
	while (**s2 != '\0')
		m[j++] = *(*s2)++;
	m[j] = '\0';
	ft_strdel(&temp1);
	ft_strdel(&temp2);
	return (m);
}
