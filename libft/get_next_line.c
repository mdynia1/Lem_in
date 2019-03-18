/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <mdynia@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:04:30 by mdynia            #+#    #+#             */
/*   Updated: 2018/10/02 18:04:35 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl_struct			*create_struct(t_gnl_struct **a_structs, int fd)
{
	t_gnl_struct		*new;

	new = *a_structs;
	while (new)
	{
		if (new->fd == fd)
			return (new);
		new = new->next;
	}
	new = ft_memalloc(sizeof(t_gnl_struct));
	new->str = ft_strnew(0);
	new->fd = fd;
	new->next = *a_structs;
	*a_structs = new;
	return (new);
}

void					ft_to_save(t_gnl_struct *st, int i)
{
	char				*to_save;
	int					l;
	int					k;

	l = 0;
	k = i;
	while (st->str[i] != '\0')
	{
		i++;
		l++;
	}
	to_save = (char *)ft_memalloc(sizeof(char) * l);
	l = 0;
	while (st->str[k] != '\0')
	{
		to_save[l] = st->str[k + 1];
		k++;
		l++;
	}
	ft_strcpy(st->str, to_save);
	free(to_save);
}

void					to_terminate(t_gnl_struct *st, char **line)
{
	char				*to_print;
	int					i;

	i = 0;
	while (st->str[i] != '\n' && st->str[i] != '\0')
		i++;
	to_print = (char *)ft_memalloc(sizeof(char) * i);
	i = 0;
	while (st->str[i] != '\n' && st->str[i] != '\0')
	{
		to_print[i] = st->str[i];
		i++;
	}
	to_print[i] = '\0';
	*line = ft_strdup(to_print);
	ft_to_save(st, i);
	free(to_print);
}

char					*ft_tojoin(char *s1, char *s2)
{
	char				*m;
	size_t				i;
	size_t				j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	m = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
	free(s1);
	return (m);
}

int						get_next_line(const int fd, char **line)
{
	static t_gnl_struct	*gnl_all;
	t_gnl_struct		*current;
	char				buff[BUFF_SIZE + 1];
	int					len;
	char				*tmp;

	if (fd < 0 || read(fd, NULL, 0) < 0 || line == NULL)
		return (-1);
	current = create_struct(&gnl_all, fd);
	if (ft_strchr(current->str, '\n') == NULL)
	{
		while ((len = read(fd, buff, BUFF_SIZE)))
		{
			buff[len] = '\0';
			tmp = ft_tojoin(current->str, buff);
			current->str = tmp;
			if (ft_strchr(current->str, '\n') != NULL)
				break ;
		}
	}
	if (ft_strlen(current->str) == 0)
		return (0);
	to_terminate(current, line);
	return (1);
}
