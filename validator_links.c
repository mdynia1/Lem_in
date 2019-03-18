/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_links.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <mdynia@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:06:38 by mdynia            #+#    #+#             */
/*   Updated: 2018/10/02 18:06:39 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_data		*room_existance(char *str, t_lemin *all)
{
	t_data	*tmp;

	tmp = all->r;
	while (tmp)
	{
		if (tmp->type == 1 && !ft_strcmp(tmp->name, str))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			duplicate_link(t_data *room1, t_data *room2)
{
	t_link	*tmp;

	tmp = room1->link;
	while (tmp)
	{
		if (!ft_strcmp(tmp->room->name, room2->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		link_linker(t_data *room1, t_data *room2)
{
	t_link	*new;

	if (!duplicate_link(room1, room2))
	{
		new = (t_link*)ft_memalloc(sizeof(t_link));
		new->room = room2;
		if (!room1->link)
			room1->link = new;
		else
		{
			new->next = room1->link;
			room1->link = new;
		}
	}
}

int			links_validator(char *str, t_lemin *all)
{
	char	**details;
	t_data	*room1;
	t_data	*room2;
	int		k;

	k = 0;
	details = ft_strsplit(str, '-');
	while (details[k])
		k++;
	if (k == 2)
	{
		room1 = room_existance(details[0], all);
		room2 = room_existance(details[1], all);
		delete_str(details);
		if (room1 && room2)
		{
			link_linker(room1, room2);
			link_linker(room2, room1);
			return (1);
		}
	}
	return (0);
}
