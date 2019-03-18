/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:57:04 by mdynia            #+#    #+#             */
/*   Updated: 2018/09/02 15:57:26 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <unistd.h>
# include "libft/libft.h"

struct s_data;

typedef struct		s_link
{
	struct s_data	*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_road
{
	int				steps;
	t_link			*links;
	struct s_road	*next;
	int				active;
}					t_road;

typedef struct		s_data
{
	char			*to_print;
	int				type;
	char			*name;
	int				x;
	int				y;
	int				used;
	int				occupied;
	int				*occupied_end;
	t_link			*link;
	struct s_data	*next;
}					t_data;

typedef struct		s_lemin
{
	char			*line;
	int				ants;
	int				fd;
	int				gap;
	int				stop;
	int				to_print;
	int				map_print;
	int				one_road;
	int				steps_number;
	int				l_count;
	t_data			*start;
	t_data			*end;
	t_data			*r;
	t_link			*links;
	t_road			*roads;
}					t_lemin;

t_road				*to_copy_road(t_link *possible_way, int steps,
	t_link *tail);
int					valid_data(t_lemin *all);
int					links_validator(char *str, t_lemin *all);
void				link_linker(t_data *room1, t_data *room2);
int					duplicate_link(t_data *room1, t_data *room2);
t_data				*room_existance(char *str, t_lemin *all);
int					rooms_validator(t_lemin *all, t_data *d, char **str);
int					unique_room(t_lemin *all, t_data *d);
int					ft_ants_nmb(t_lemin *all);
void				roads_activation(t_lemin *all, int i, int steps, int s);
void				context_printer(t_lemin *all);
void				start_end_dealer(t_lemin *all, t_road *road);
int					unique_road(t_lemin *all, t_road *current_road);
void				path_search(t_lemin *all, t_link *link, t_link *way,
	int steps);
void				my_dealer(t_lemin *all, t_road *road, int i, int exit);
int					helper(t_lemin *all, t_link *road, int ant, int *exit);
void				roads_recorder(t_lemin *all, t_link *possible_way,
	int steps);
void				roads_linker(t_road *a, t_road *my_way);
void				initialize_room(t_data *l);
void				initialize_lemin(t_lemin *all);
int					delete_str(char **str);
void				delete_data(t_lemin *data);
t_road				*list_copy(t_link *possible_way);
void				to_print_road(t_link *possible_way, int steps);
#endif
