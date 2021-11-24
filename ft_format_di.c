/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:50:34 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/22 13:50:35 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_ret(long num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_di(va_list ptr, int fd)
{
	long	nb;

	nb = va_arg(ptr, int);
	ft_putnbr(nb, fd);
	return (count_ret(nb));
}
