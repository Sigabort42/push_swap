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
		ft_verif_command.c \
		ft_init_pile_a.c \
		ft_listlast.c \
		ft_swap_a.c \
		ft_swap_b.c \
		ft_swap_s.c \
		ft_push_a.c \
		ft_push_b.c \
		ft_rotate_a.c \
		ft_rotate_b.c \
		ft_rotate_r.c \
		ft_reverse_a.c \
		ft_reverse_b.c \
		ft_reverse_r.c \
		ft_exec_command.c \
		ft_verif_tri.c \
		ft_altoi.c \

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -C libft/
	@$(CC) -I $(HEADER) $(OBJS) -L./libft -lft main.c -o $(NAME)

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJS)

fclean:	clean
	@make -C libft/ fclean
	@/bin/rm -rf $(NAME)

re: fclean all