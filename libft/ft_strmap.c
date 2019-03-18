/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:26:16 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/03 15:30:35 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cp;
	int		i;

	if (!s || !f)
		return (NULL);
	cp = ft_strnew(ft_strlen(s));
	if (cp != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			cp[i] = f(s[i]);
			i++;
		}
		cp[i] = '\0';
		return (cp);
	}
	return (0);
}
