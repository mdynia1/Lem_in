/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_removal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <mdynia@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:09:09 by mdynia            #+#    #+#             */
/*   Updated: 2018/10/02 18:09:10 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				delete_str(char **str)
{
	int			x;

	x = 0;
	while (str[x])
		ft_memdel((void*)&str[x++]);
	free(str);
	return (0);
}

static void		delete_link(t_link **link)
{
	if ((*link)->next)
		delete_link(&(*link)->next);
	ft_memdel((void*)link);
}

static void		delete_rooms(t_data **room, int i)
{
	if ((*room)->next && i < 250000)
		delete_rooms(&(*room)->next, i + 1);
	if ((*room)->type == 1)
	{
		if ((*room)->name)
			free((*room)->name);
		if ((*room)->occupied_end)
			free((*room)->occupied_end);
		if ((*room)->link)
			delete_link(&(*room)->link);
	}
	if ((*room)->to_print)
		free((*room)->to_print);
	ft_memdel((void*)room);
}

static void		delete_road(t_road **road)
{
	if ((*road)->next)
		delete_road(&(*road)->next);
	if ((*road)->links)
		delete_link(&(*road)->links);
	ft_memdel((void*)road);
}

void			delete_data(t_lemin *data)
{
	if (data->roads)
		delete_road(&data->roads);
	if (data->r)
		delete_rooms(&data->r, 0);
}
