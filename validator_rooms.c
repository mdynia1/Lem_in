/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <mdynia@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:06:27 by mdynia            #+#    #+#             */
/*   Updated: 2018/10/02 18:06:28 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			unique_room(t_lemin *all, t_data *d)
{
	t_data *tmp;

	tmp = all->r;
	while (tmp)
	{
		if (tmp->type == 1 && !ft_strcmp(tmp->name, d->name))
			return (0);
		if ((d->x == tmp->x) && (d->y == tmp->y))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			rooms_validator(t_lemin *all, t_data *d, char **str)
{
	int		i;

	i = 0;
	while (str[1] && ft_isdigit(str[1][i++]))
		if (str[1][i] == '\0')
			d->x = ft_atoi(str[1]);
	i = 0;
	while (str[2] && ft_isdigit(str[2][i++]))
		if (str[2][i] == '\0')
			d->y = ft_atoi(str[2]);
	d->name = ft_strdup(str[0]);
	if (d->name && d->x != -1 && d->y != -1 && unique_room(all, d))
	{
		if (all->start && all->start->name && !ft_strcmp(all->start->name, "L"))
			all->start = d;
		else if (all->end && all->end->name && !ft_strcmp(all->end->name, "L"))
		{
			d->occupied_end = (int *)ft_memalloc(sizeof(int) * all->ants);
			all->end = d;
		}
		d->type = 1;
		return (1);
	}
	return (0);
}
