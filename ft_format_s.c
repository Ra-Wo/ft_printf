/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:05:47 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/21 15:36:35 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s(va_list ptr, int fd)
{
	char	*str;
	int		i;

	str = va_arg(ptr, char *);
	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		i += 6;
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i], fd);
			i++;
		}
	}
	return (i);
}
