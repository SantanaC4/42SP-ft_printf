# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 20:26:21 by edrodrig          #+#    #+#              #
#    Updated: 2021/10/29 19:35:56 by edrodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
LIBFT 	= ./libft/libft.a

NAME	= libftprintf.a

SRCS = ft_printf.c \
#	ft_printf_utils.c \
	ft_resolve_dec.c \
	ft_resolve_str.c \
	ft_resolve_ptr.c \
	ft_resolve_chr.c \
	ft_resolve_prc.c \
	ft_resolve_hex.c \
	ft_resolve_uns.c \
	ft_resolve_flg.c \
	ft_put_space.c


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
