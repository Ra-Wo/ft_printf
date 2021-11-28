NAME 	= libftprintf.a

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= 	ft_format_c.c ft_format_p.c ft_format_u.c ft_printf.c	\
			ft_putchar.c ft_strlen.c ft_formal_X.c ft_format_di.c	\
			ft_format_s.c ft_format_x.c ft_putnbr.c	convert_base.c	\

OBJS	= $(SRCS:c=o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o: %.c ft_printf.h
	$(CC) ${CFLAGS} -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
