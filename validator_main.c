/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <mdynia@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:06:06 by mdynia            #+#    #+#             */
/*   Updated: 2018/10/02 18:21:59 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					ft_ants_nmb(t_lemin *all)
{
	int				i;
	long long		ants;

	ants = 0;
	i = 0;
	while (all->line[i])
		if (ft_isdigit(all->line[i++]) == 0 || i > 10)
			return (0);
	if (all->ants == -1)
	{
		ants = ft_atoi(all->line);
		if (ants > 2147483647 || ants < 1)
			return (0);
		all->ants = ants;
		if (all->ants == 1)
			all->one_road = 1;
		return (1);
	}
	return (0);
}

int					data_linker(t_lemin *all, t_data *d, char **str)
{
	t_data			*temp;

	temp = all->r;
	if (!all->r)
		all->r = d;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = d;
	}
	delete_str(str);
	free(all->line);
	return (1);
}

void				flag_helper(t_lemin *all, char **str, int i)
{
	if (i == 1 && !ft_strcmp(str[0], "#roads_printer"))
		all->to_print = 1;
	else if (i == 1 && !ft_strcmp(str[0], "#no_map"))
		all->map_print = 0;
	else if (i == 1 && !ft_strcmp(str[0], "#one_road"))
		all->one_road = 1;
	else if (i == 1 && !ft_strcmp(str[0], "#steps_number"))
		all->steps_number = 1;
}

int					comments_dealer(t_lemin *all, char **str, int i)
{
	static t_data	l;
	static t_data	l2;

	if (i == 1 && !ft_strcmp(str[0], "##start"))
	{
		if ((all->end && !ft_strcmp(all->end->name, "L"))
			|| (all->start && all->start->name))
			return (0);
		all->start = &l;
		all->start->name = "L";
	}
	else if (i == 1 && !ft_strcmp(str[0], "##end"))
	{
		if ((all->start && !ft_strcmp(all->start->name, "L"))
			|| (all->end && all->end->name))
			return (0);
		all->end = &l2;
		all->end->name = "L";
	}
	else
		flag_helper(all, str, i);
	return (1);
}

int					valid_data(t_lemin *all)
{
	char			**str;
	t_data			*data;
	int				i;

	i = 0;
	data = (t_data *)ft_memalloc(sizeof(t_data));
	initialize_room(data);
	data->to_print = ft_strdup(all->line);
	str = ft_strsplit(all->line, ' ');
	while (str[i] != NULL)
		i++;
	if (str[0][0] != '#')
	{
		if (all->ants == -1 && i == 1 && ft_ants_nmb(all))
			return (data_linker(all, data, str));
		else if (all->ants != -1 && ((i == 3 && rooms_validator(all, data, str))
	|| (i == 1 && ft_strchr(str[0], '-') && links_validator(*str, all))))
			return (data_linker(all, data, str));
	}
	else if (str[0][0] == '#' && comments_dealer(all, str, i))
		return (data_linker(all, data, str));
	data_linker(all, data, str);
	return (0);
}
