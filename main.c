/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <mdynia@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:08:43 by mdynia            #+#    #+#             */
/*   Updated: 2018/10/02 18:08:46 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		initialize_lemin(t_lemin *all)
{
	all->stop = -1;
	all->gap = 20;
	all->ants = -1;
	all->fd = 0;
	all->start = NULL;
	all->end = NULL;
	all->roads = NULL;
	all->line = NULL;
	all->to_print = 0;
	all->map_print = 1;
	all->one_road = 0;
	all->steps_number = 0;
	all->l_count = 0;
}

void		initialize_room(t_data *l)
{
	l->to_print = NULL;
	l->type = -1;
	l->name = NULL;
	l->x = -1;
	l->y = -1;
	l->occupied = 0;
	l->used = 0;
}

int			main(void)
{
	t_lemin	all;
	t_link	possible_way;

	initialize_lemin(&all);
	while (get_next_line(all.fd, &all.line) > 0)
		if (*all.line == 'L' || *all.line == ' ' || !all.line
			|| !ft_strlen(all.line) || !valid_data(&all))
			break ;
	if (all.start && all.end && ft_strcmp(all.start->name, "L")
		&& ft_strcmp(all.end->name, "L") && all.start->link && all.end->link)
	{
		possible_way.room = all.end;
		possible_way.next = NULL;
		while (!all.roads && (all.stop == 1 || all.stop == -1))
		{
			all.stop = 0;
			path_search(&all, all.end->link, &possible_way, 0);
			all.gap *= 2;
		}
	}
	all.roads ? roads_activation(&all, 1, 0, 0) : ft_printf("Invalid data!\n");
	delete_data(&all);
	return (0);
}
