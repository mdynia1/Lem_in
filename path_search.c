/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <mdynia@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:09:34 by mdynia            #+#    #+#             */
/*   Updated: 2018/10/02 18:09:35 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			visted_room(t_link *links, t_data *room)
{
	t_link	*link;

	link = links;
	while (link)
	{
		if ((int)link->room->name == (int)room->name)
			return (0);
		link = link->next;
	}
	return (1);
}

void		roads_linker(t_road *a, t_road *my_way)
{
	t_road	*tmp;

	tmp = a;
	while (tmp && tmp->steps <= my_way->steps)
	{
		if (tmp->next && tmp->next->steps >= my_way->steps)
		{
			my_way->next = tmp->next;
			tmp->next = my_way;
			break ;
		}
		else if (!tmp->next)
		{
			tmp->next = my_way;
			break ;
		}
		tmp = tmp->next;
	}
}

void		roads_recorder(t_lemin *all, t_link *possible_way, int steps)
{
	t_road	*my_way;

	if (!all->roads)
	{
		all->roads = to_copy_road(possible_way, steps, NULL);
		all->to_print == 1 ? to_print_road(possible_way, steps) : NULL;
		all->l_count = steps;
	}
	else if (all->one_road == 0 || steps < all->l_count)
	{
		my_way = to_copy_road(possible_way, steps, NULL);
		all->to_print == 1 ? to_print_road(possible_way, steps) : NULL;
		if (steps < all->roads->steps)
		{
			my_way->next = all->roads;
			all->roads = my_way;
			all->l_count = steps;
		}
		else
			roads_linker(all->roads, my_way);
	}
}

void		path_search(t_lemin *all, t_link *link, t_link *way, int steps)
{
	t_link	*tmp;

	if (steps < all->gap && (all->one_road == 0 || all->l_count == 0
		|| steps < all->l_count))
	{
		if (link->next)
			path_search(all, link->next, way, steps);
		if (link->room->type == 1 && visted_room(way, link->room))
		{
			if (link->room->name &&
			!ft_strcmp(link->room->name, all->start->name))
				roads_recorder(all, way, steps + 1);
			else if (link->room->link->next)
			{
				tmp = (t_link *)ft_memalloc(sizeof(t_link));
				tmp->room = link->room;
				tmp->next = way;
				way = tmp;
				path_search(all, link->room->link, way, steps + 1);
				if (steps + 1 == all->gap)
					all->stop = 1;
				ft_memdel((void*)&way);
			}
		}
	}
}
