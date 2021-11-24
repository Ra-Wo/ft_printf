/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:49:04 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/23 08:49:09 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_ret(unsigned long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
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

static void	put_number(unsigned int nb, int fd)
{
	unsigned int	number;
	unsigned int	x;

	x = nb;
	if (nb > 0)
	{
		put_number(nb / 10, fd);
		number = (x % 10) + '0';
		write(fd, &number, 1);
	}
}

int	ft_u(va_list ptr, int fd)
{
	unsigned int	nb;

	nb = va_arg(ptr, unsigned int);
	if (nb == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else
		put_number(nb, fd);
	return (count_ret(nb));
}
