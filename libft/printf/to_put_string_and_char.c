/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_put_string_and_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:43:27 by mdynia            #+#    #+#             */
/*   Updated: 2018/03/16 19:43:29 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	to_put_string_and_char(int flag, int width, int prec, char **to_print)
{
	char	*to_j;
	char	*to_cut;
	int		s_or_z;

	if (prec == -1)
		ft_bzero(*to_print, ft_strlen(*to_print));
	s_or_z = flag == ZERO ? '0' : ' ';
	if (width != 0 || prec != 0)
	{
		if (prec < (int)ft_strlen(*to_print) && prec != -1 && prec != 0)
		{
			to_cut = ft_strnew(prec);
			ft_strncpy(to_cut, *to_print, prec);
			ft_strdel(to_print);
			*to_print = to_cut;
		}
		if (width > (int)ft_strlen(*to_print))
		{
			to_j = ft_strnew(width - ft_strlen(*to_print));
			to_j = ft_memset(to_j, s_or_z, (width - ft_strlen(*to_print)));
			*to_print = MINUSES(flag) ? ft_strjoin_f(to_print, &to_j)
				: ft_strjoin_f(&to_j, to_print);
		}
	}
}
