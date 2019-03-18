/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:51:32 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/14 17:51:39 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# include "libft/libft.h"
# define BUFF_SIZE 6

typedef struct			s_gnl_struct
{
	int					fd;
	char				*str;
	struct s_gnl_struct	*next;
}						t_gnl_struct;

int						get_next_line(const int fd, char **line);

#endif
