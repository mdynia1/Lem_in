/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_into_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:20:27 by mdynia            #+#    #+#             */
/*   Updated: 2018/03/16 20:20:29 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		to_get_x(int *flag)
{
	int	x;

	x = 0;
	while (*flag >= 49)
	{
		*flag -= 49;
		x++;
	}
	return (x);
}

char	*precision_helper(int flag, int x, int prec, char *to_join)
{
	if (SPACES(flag))
		to_join[0] = ' ';
	else if (HASHTAGS(flag))
	{
		to_join[0] = '0';
		if (x > 0)
			to_join[1] = x == 1 ? 'X' : 'x';
		else
			prec = prec == 0 ? prec : prec - 1;
	}
	else
		to_join[0] = (PLUSES(flag) || flag == 30) ? '+' : '-';
	x != 0 ? ft_memset(to_join + 2, '0', (size_t)prec)
		: ft_memset(to_join + 1, '0', (size_t)prec);
	return (to_join);
}

void	to_employ_precision(int flag, int prec, char **to_print, int s_or_z)
{
	char	*to_join;
	int		x;

	x = flag >= 49 ? to_get_x(&flag) : 0;
	if (prec >= 0)
	{
		if (HASHTAGS(flag) && x > 0)
			to_join = ft_strnew((size_t)prec + 2);
		else
			to_join = (flag >= NEGATIVE || NEED(flag)) ?
					ft_strnew((size_t)prec + 1) : ft_strnew((size_t)prec);
		if ((flag >= NEGATIVE || NEED(flag)) && s_or_z != '0')
			to_join = precision_helper(flag, x, prec, to_join);
		else
			ft_memset(to_join, '0', prec);
		*to_print = ft_strjoin_f(&to_join, to_print);
	}
}

void	to_employ_width(int flag, int width, int s, char **to_print)
{
	char	*to_join;

	if (width != 0)
	{
		to_join = ft_strnew(width);
		if (((to_get_x(&flag) != 0 && HASHTAGS(flag)) || P(flag)) && s == '0')
		{
			if (flag == SPACE + ZERO)
				*to_join = ' ';
			else if (HASHTAGS(flag))
			{
				to_join[0] = '0';
				to_join[1] = 'x';
				width = width - ft_strlen(*to_print) > 0 ? width - 1 : width;
			}
			else
				*to_join = flag == PLUS + ZERO ? '+' : '-';
			HASHTAGS(flag) ? ft_memset(to_join + 2, s, (size_t)width - 1)
						: ft_memset(to_join + 1, s, (size_t)width - 1);
		}
		else
			ft_memset(to_join, s, (size_t)width);
		*to_print = MINUSES(flag) ? ft_strjoin_f(to_print, &to_join)
								: ft_strjoin_f(&to_join, to_print);
	}
}

void	to_sort_width_and_prec(int flag, int w, int prec, char **to_print)
{
	int		s_or_z;
	int		len;
	int		x;
	int		flag_x;

	flag_x = flag;
	x = flag >= 49 ? to_get_x(&flag) : 0;
	len = (int)ft_strlen(*to_print);
	s_or_z = ' ';
	if (prec == -1 && *to_print[0] == '0')
		ft_bzero(*to_print, (size_t)len);
	if (s_or_z == ' ' && (w - len) > 0 && (ZEROS(flag) || NEGATIVES(flag)))
		s_or_z = '0';
	if (prec != -1 || x == 0 || x == 3)
		prec = prec >= len ? (prec - len) : -2;
	if (prec == -2 && (PLUSES(flag) || ONE_SIGN(flag) || HASHTAGS(flag)))
		prec = 0;
	prec = (x == 0 && (*to_print[0] == '0') && (HASHTAGS(flag))) ? -1 : prec;
	if (flag >= NEGATIVE && (prec >= 0 || (w - len >= 0 && s_or_z == '0')))
		*to_print[0] = '0';
	flag_x -= (**to_print == '0' && x != 0 && x != 3 && flag >= 16) ? 16 : 0;
	to_employ_precision(flag_x, prec, to_print, s_or_z);
	len = (int)ft_strlen(*to_print);
	w = w > len ? (w - len) : 0;
	to_employ_width(flag_x, w, s_or_z, to_print);
}
