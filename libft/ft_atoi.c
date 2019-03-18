/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:54:51 by mdynia            #+#    #+#             */
/*   Updated: 2017/11/26 13:38:46 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' ||
		c == '\n' || c == '\f' || c == '\r');
}

static int	sub_func(unsigned long int n, const char *str, int i, int flag)
{
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if ((n > 922337203685477580 || (n == 922337203685477580
			&& (str[i] - '0') > 7)) && flag == 0)
			return (-1);
		else if ((n > 922337203685477580 || (n == 922337203685477580
			&& (str[i] - '0') > 8)) && flag == 1)
			return (0);
		n = n * 10;
		n += (int)str[i] - 48;
		i++;
	}
	return (n);
}

int			ft_atoi(const char *str)
{
	int					i;
	unsigned long int	n;
	int					flag;

	i = 0;
	n = 0;
	flag = 0;
	while (ft_whitespaces(str[i]))
		i++;
	if (str[i] == '-')
		flag = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	n = sub_func(n, str, i, flag);
	if ((int)n == -1)
		return (-1);
	if ((int)n == 0)
		return (0);
	if (flag == 1)
		return (-n);
	else
		return (n);
}
