/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 19:19:04 by mdynia            #+#    #+#             */
/*   Updated: 2018/02/10 19:35:09 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_printf(char *str, ...)
{
	va_list	argm;
	int		count;

	count = 0;
	va_start(argm, str);
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			count += to_sort_types(&str, argm, 0);
			if (TYPES_LIST(*str))
				str++;
		}
		else
		{
			ft_putchar(*str++);
			count++;
		}
	}
	va_end(argm);
	return (count);
}
