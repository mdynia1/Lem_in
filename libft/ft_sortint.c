/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:54:47 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/06 16:57:19 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_sortint(int *array, int len)
{
	int	i;

	if (!array || !len)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		if (array[i] > array[i + 1])
		{
			ft_swap(&array[i], &array[i + 1]);
			i = 0;
		}
		i++;
	}
	return (array);
}
