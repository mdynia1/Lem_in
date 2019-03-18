/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <mdynia@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:51:15 by mdynia            #+#    #+#             */
/*   Updated: 2018/10/02 18:51:18 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_road	*to_copy_road(t_link *possible_way, int steps, t_link *tail)
{
	t_road *my_way;
	t_link *tmp;

	my_way = (t_road *)ft_memalloc(sizeof(t_road));
	my_way->steps = steps;
	tmp = possible_way;
	while (tmp)
	{
		if (!my_way->links)
		{
			my_way->links = (t_link *)ft_memalloc(sizeof(t_link));
			my_way->links->room = tmp->room;
			my_way->links->next = NULL;
			tail = my_way->links;
		}
		else
		{
			tail->next = (t_link *)ft_memalloc(sizeof(t_link));
			tail = tail->next;
			tail->room = tmp->room;
			tail->next = NULL;
		}
		tmp = tmp->next;
	}
	return (my_way);
}

void	to_print_road(t_link *possible_way, int steps)
{
	t_link *tmp;

	tmp = possible_way;
	ft_printf("%s", "Possible road: ");
	while (tmp)
	{
		ft_printf("%s ", tmp->room->name);
		tmp = tmp->next;
	}
	ft_printf(" == %d\n", steps);
}
