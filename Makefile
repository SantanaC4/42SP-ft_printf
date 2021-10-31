# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 20:26:21 by edrodrig          #+#    #+#              #
#    Updated: 2021/10/31 03:40:10 by edrodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
LIBFT 	= ./libft/libft.a

NAME	= libftprintf.a

SRCS = ft_printf.c \
		ft_putptr.c \
		ft_putnbr_base.c \
		ft_putzu.c

OBJS = ${SRCS:.c=.o}


CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@$(MAKE) -C ./libft
	@cp libft/libft.a $(NAME)
	@ar -rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
	@$(MAKE) clean -C ./libft
	@rm -f ${OBJS}
	@rm -f ${BOBJS}

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f ${NAME}
	@rm a.out

re: fclean all

bonus: all

test: all
	${CC} -g main.c libftprintf.a libft/libft.a
	./a.out
	@make fclean

.PHONY: all, bonus, clean, fclean, re
