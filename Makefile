#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 17:23:52 by elbenkri          #+#    #+#              #
#    Updated: 2018/01/13 18:11:36 by elbenkri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	checker

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror


HEADER	=	includes/

SRCS	=	ft_init_tab_func.c \

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	make -C libft/
	$(CC) -I $(HEADER) $(OBJS) -L./libft -lft main.c -o $(NAME)

clean:
	make -C libft/ clean
	/bin/rm -rf $(OBJS)

fclean:	clean
	make -C libft/ fclean
	/bin/rm -rf $(NAME)

re: fclean all