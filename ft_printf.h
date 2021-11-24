/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:21:40 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/21 15:30:41 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TYPE "cspdiuxX"
# define UPPER_HEXADECIMAL "0123456789ABCDEF"
# define LOWER_HEXADECIMAL "0123456789abcdef"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *str, ...);
unsigned int	ft_strlen(const char *str);
void			ft_putchar(char c, int fd);
void			ft_putnbr(int n, int fd);
int				ft_c(va_list ptr, int fd);
int				ft_s(va_list ptr, int fd);
int				ft_p(va_list ptr, int fd);
int				ft_di(va_list ptr, int fd);
int				ft_u(va_list ptr, int fd);
int				ft_x(va_list ptr, int fd);
int				ft_x_upper(va_list ptr, int fd);

#endif