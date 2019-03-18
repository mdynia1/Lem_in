/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:45:03 by mdynia            #+#    #+#             */
/*   Updated: 2017/12/01 19:52:55 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxtlst;

	lst = *alst;
	while (lst)
	{
		nxtlst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxtlst;
	}
	*alst = NULL;
}
