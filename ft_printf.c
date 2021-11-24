/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:31:45 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/21 15:36:46 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char *s, int index, int fd, va_list ptr)
{
	int		x;
	int		(*print_arg[8])(va_list ptr, int fd);

	print_arg[0] = ft_c;
	print_arg[1] = ft_s;
	print_arg[2] = ft_p;
	print_arg[3] = ft_di;
	print_arg[4] = ft_di;
	print_arg[5] = ft_u;
	print_arg[6] = ft_x;
	print_arg[7] = ft_x_upper;
	index++;
	x = 0;
	while (TYPE[x])
	{
		if (s[index] == TYPE[x])
			return (print_arg[x](ptr, fd));
		x++;
	}
	if (s[index] == '%')
	{
		write(fd, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		fd;
	int		index;
	int		c;

	fd = 1;
	index = 0;
	c = 0;
	va_start(ptr, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			c += (check_type(str, index, fd, ptr) - 2);
			index += 2;
			continue ;
		}
		ft_putchar(str[index++], fd);
	}
	va_end(ptr);
	return (index + c);
}

/* 
#include <stdio.h>
int main(void)
{

	printf("\nstd|| %d ||\n", printf(" %x ", -2));
	printf("\nremake|| %d ||\n", ft_printf(" %x ", -2));

	return 0;
}
 */