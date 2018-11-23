#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 17:23:52 by elbenkri          #+#    #+#              #
#    Updated: 2018/11/23 03:54:17 by elbenkri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	checker

NAME2	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror #-g3 -fsanitize=address

HEADER	=	includes/

SRCS	=	ft_init_tab_func.c \
			ft_verif_command.c \
			ft_utils.c \
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

SRCS2	=	prog_swap/ft_phase_one.c \
			prog_swap/ft_count_pile.c \
			prog_swap/main.c \
			prog_swap/ft_phase_two.c \

OBJS	=	$(SRCS:.c=.o)

OBJS2	=	$(SRCS2:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJS2)
	@make -C libft/
	@$(CC) -I $(HEADER) $(OBJS) -L./libft -lft main.c -o $(NAME)
	@$(CC) -I $(HEADER) $(OBJS) $(OBJS2) -L./libft -lft -o $(NAME2)

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJS)
	@/bin/rm -rf $(OBJS2)

fclean:	clean
	@make -C libft/ fclean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(NAME2)

re: fclean all
