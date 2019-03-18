/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:33:46 by mdynia            #+#    #+#             */
/*   Updated: 2017/11/28 20:13:56 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordscount(char *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			n++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (n);
}

static int	ft_wordlength(char *s, char c, int i)
{
	int		count;

	count = 0;
	while (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

static void	ft_putword(char const *s, char c, char **w, int k)
{
	int		j;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		w[k] = (char *)malloc(sizeof(char) *
			(ft_wordlength((char *)s, c, i) + 1));
		j = 0;
		while (s[i] != c && s[i] != '\0')
		{
			w[k][j] = s[i];
			j++;
			i++;
		}
		w[k][j] = '\0';
		k++;
	}
	w[k] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**w;

	if (s == NULL)
		return (NULL);
	w = (char **)malloc(sizeof(char *) * ft_wordscount((char *)s, c) + 1);
	if (w != NULL)
	{
		ft_putword(s, c, w, 0);
		return (w);
	}
	return (NULL);
}
