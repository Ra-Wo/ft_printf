/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:07:23 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/23 09:07:26 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_lower(va_list ptr, int fd)
{
	char	*str;
	int		i;

	str = convert_base(va_arg(ptr, unsigned int), LOWER_HEXADECIMAL);
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], fd);
		i++;
	}
	free(str);
	return (i);
}
