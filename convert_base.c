/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:55:34 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/26 08:55:36 by roudouch         ###   ########.fr       */
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

char	*convert_base(unsigned int num, char *base)
{
	char	to[50];
	int		i;

	if (num == 0)
		return (reverse("0"));
	i = 0;
	while (num > 0)
	{
		to[i++] = base[num % ft_strlen(base)];
		if (num > ft_strlen(base))
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
