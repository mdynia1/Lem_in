/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <mdynia@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:06:58 by mdynia            #+#    #+#             */
/*   Updated: 2018/10/02 18:06:59 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				end_helper(t_lemin *all, t_link *tmp, int ant, int *exit)
{
	int			k;

	k = 0;
	while (k < all->ants)
	{
		if (tmp->room->occupied_end[k] == ant)
		{
			ft_printf("L%d-%s", ant, tmp->room->name);
			tmp->room->occupied_end[k] = -1;
			(*exit)++;
			return (1);
		}
		k++;
	}
	return (0);
}

int				helper(t_lemin *all, t_link *road, int ant, int *exit)
{
	t_link		*tmp;
	static int	i = -1;

	tmp = road;
	while (tmp)
	{
		if (tmp->room->occupied == ant)
		{
			ft_printf("L%d-%s", ant, tmp->room->name);
			tmp->room->occupied = 0;
			if (tmp->next->next)
				tmp->next->room->occupied = ant;
			else if (tmp->next && !tmp->next->next)
				tmp->next->room->occupied_end[++i] = ant;
			return (1);
		}
		else if (tmp->room == all->end && tmp->room->occupied_end[0] != 0)
			return (end_helper(all, tmp, ant, exit));
		tmp = tmp->next;
	}
	return (0);
}

int				road_filler(t_lemin *all, t_road *road, int *ant)
{
	t_road		*tmp;

	tmp = road;
	while (tmp && *ant <= all->ants)
	{
		if (tmp->active == 1)
		{
			if (tmp->links->room->occupied == 0)
				tmp->links->room->occupied = *ant;
			(*ant)++;
		}
		tmp = tmp->next;
	}
	return (0);
}

void			flag_printer(t_lemin *all)
{
	static int	i = 1;

	if (all->steps_number == 1)
		ft_printf("  === %d\n", i++);
	else
		ft_printf("\n");
}

void			my_dealer(t_lemin *all, t_road *road, int i, int exit)
{
	t_road		*roads;
	static int	ant = 1;

	roads = road;
	while (exit < all->ants)
	{
		i = road_filler(all, road, &ant);
		while (i < ant && ++i)
		{
			roads = road;
			while (roads)
			{
				if (roads->active == 1)
					if (helper(all, roads->links, i, &exit))
					{
						if (i + 1 < ant)
							ft_printf(" ");
						break ;
					}
				roads = roads->next;
			}
		}
		flag_printer(all);
	}
}
