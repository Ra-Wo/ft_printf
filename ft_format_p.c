/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:18:12 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/22 09:18:15 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*reverse(char *str)
{
	char	*backup;
	int		i;
	int		x;

	i = ft_strlen(str);
	backup = malloc((i + 1) * sizeof(char));
	x = 0;
	i--;
	while (str[i])
	{
		backup[x++] = str[i--];
	}
	backup[x] = '\0';
	return (backup);
}

static char	*convert(unsigned long num, char *base)
{
	char	to[100];
	int		i;

	i = 0;
	if (num == 0)
		return (reverse("0"));
	while (num != 0)
	{
		to[i++] = base[num % ft_strlen(base)];
		if (num > (unsigned long)ft_strlen(base))
		{
			num /= ft_strlen(base);
			continue ;
		}
		else if (num > 0)
		{
			num /= ft_strlen(base);
			continue ;
		}
		else
			break ;
	}
	to[i] = '\0';
	return (reverse(to));
}

int	ft_p(va_list ptr, int fd)
{
	char	*str;
	int		i;

	str = convert(va_arg(ptr, unsigned long), LOWER_HEXADECIMAL);
	i = 0;
	ft_putchar('0', fd);
	ft_putchar('x', fd);
	while (str[i])
	{
		ft_putchar(str[i], fd);
		i++;
	}
	free(str);
	return (i + 2);
}
