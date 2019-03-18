/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roads_activation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <mdynia@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:07:08 by mdynia            #+#    #+#             */
/*   Updated: 2018/10/02 18:07:09 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		start_end_dealer(t_lemin *all, t_road *road)
{
	int		ant;

	ant = 1;
	while (ant <= all->ants)
	{
		ft_printf("L%d-%s", ant, road->links->room->name);
		if (ant != all->ants)
			ft_printf(" ");
		ant++;
	}
	ft_printf("\n");
}

void		context_printer(t_lemin *all)
{
	t_data	*tmp;

	tmp = all->r;
	while (tmp)
	{
		ft_printf("%s\n", tmp->to_print);
		tmp = tmp->next;
	}
}

int			unique_road(t_lemin *all, t_road *current_road)
{
	t_link	*tmp;

	tmp = current_road->links;
	while (tmp)
	{
		if (tmp->room->used == 1 && ft_strcmp(tmp->room->name, all->end->name))
			return (0);
		tmp->room->used = 1;
		tmp = tmp->next;
	}
	return (1);
}

int			letstry(int steps, t_lemin *all, int i)
{
	int		ants;
	t_road	*tmp;
	int		s;

	s = steps - 1;
	tmp = all->roads;
	ants = 0;
	while (all->ants > ants)
	{
		if (ants + i > all->ants)
		{
			i = all->ants - ants;
			while (i > 1)
			{
				tmp = tmp->next;
				i--;
			}
			if (tmp->steps == steps)
				s += 1;
			break ;
		}
		s += 1;
		ants += i;
	}
	return (s);
}

void		roads_activation(t_lemin *all, int i, int steps, int s)
{
	t_road	*tmp;

	tmp = all->roads;
	all->map_print == 1 ? context_printer(all) : NULL;
	if (tmp->steps == 1)
		start_end_dealer(all, all->roads);
	else
	{
		while (all->one_road != 2 && steps != -1 && tmp && i <= all->ants)
		{
			if (unique_road(all, tmp))
			{
				s = letstry(tmp->steps, all, i);
				steps = steps == 0 || steps >= s ? s : -1;
				if (steps != -1 && (all->one_road == 1 || all->one_road == 0))
				{
					all->one_road = all->one_road == 1 ? 2 : 0;
					tmp->active = 1;
					i++;
				}
			}
			tmp = tmp->next;
		}
		my_dealer(all, all->roads, 1, 0);
	}
}
