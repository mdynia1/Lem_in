/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:06:52 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/03 15:32:51 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			cp[i] = f(i, s[i]);
			i++;
		}
		cp[i] = '\0';
		return (cp);
	}
	return (0);
}
