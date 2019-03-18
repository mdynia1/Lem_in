/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 20:10:27 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/01 20:40:30 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*copy;
	t_list	*start;

	if (lst == NULL || f == NULL)
		return (NULL);
	copy = f(lst);
	start = copy;
	while (lst->next)
	{
		lst = lst->next;
		if (!(copy->next = f(lst)))
		{
			free(copy->next);
			return (NULL);
		}
		copy = copy->next;
	}
	return (start);
}
