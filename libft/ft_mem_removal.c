/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_removal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:38:39 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/08 23:39:47 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mem_removal(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
}
