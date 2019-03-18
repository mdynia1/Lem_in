/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:13 by mdynia            #+#    #+#             */
/*   Updated: 2018/02/14 15:14:14 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*add_to_double(int precision, double *n)
{
	long long int	whole_part;
	double			to_move;
	double			copy_n;

	whole_part = *n;
	*n *= whole_part < 0 ? -1 : 1;
	*n -= whole_part < 0 ? whole_part * -1 : whole_part;
	copy_n = *n;
	to_move = 1.0;
	while ((copy_n *= 10) && precision--)
	{
		to_move /= 10;
		copy_n -= (int)copy_n;
	}
	*n += (((int)copy_n >= 5) && ((int)copy_n <= 9)) ? to_move : 0;
	if ((int)*n > 0)
	{
		*n -= (int)*n;
		return (ft_itoa_long(whole_part + 1));
	}
	else
		return (ft_itoa_long(whole_part));
}

char	*ft_itoa_double(double n, int precision)
{
	int				i;
	char			*fract;
	char			*whole;

	i = 0;
	precision = precision == 0 ? 6 : precision;
	precision = precision == -1 ? 0 : precision;
	whole = add_to_double(precision, &n);
	if (precision > 0)
	{
		fract = ft_strnew(precision + 1);
		fract[i++] = '.';
		while ((i <= precision + 1) && (n *= 10.0))
		{
			fract[i++] = (char)((int)n + '0');
			n -= (int)n;
		}
		if (precision > 15 && (fract[i - 1] >= '5' && fract[i - 1] <= '9'))
			fract[i - 2] += 1;
		fract[i - 1] = '\0';
		whole = ft_strjoin_f(&whole, &fract);
	}
	return (whole);
}
