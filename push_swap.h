/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:18:07 by elbenkri          #+#    #+#             */
/*   Updated: 2018/11/23 03:56:31 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "libft/libft.h"

# define SA_CMD 0
# define SA "sa"

/*
**swap a - intervertit les 2 premiers éléments au sommet de la pi.
**Ne fait rien s’il n’y en a qu’un ou aucu
*/

# define SB_CMD 1
# define SB "sb"

/*
**swap b - intervertit les 2 premiers éléments au sommet de la pi.
**Ne fait rien s’il n’y en a qu’un ou aucu
*/

# define SS_CMD 2
# define SS "ss"

/*
**sa et sb en même temp
*/

# define PA_CMD 3
# define PA "pa"

/*
**push a - prend le premier élément au sommet de b et le met s a.
**Ne fa rien si b est vide.
*/

# define PB_CMD 4
# define PB "pb"

/*
**push b - prend le premier élément au sommet de a et le met s b
**Ne fa rien si a est vide.
*/

# define RA_CMD 5
# define RA "ra"

/*
**rotate a - décale d’une position vers le haut tous les élements de la le a
**  Le premier élément devient le dernier
*/

# define RB_CMD 6
# define RB "rb"

/*
**rotate b - décale d’une position vers le haut tous les élements de la pi
**. Le premier élément devient le dern
*/

# define RR_CMD 7
# define RR "rr"

/*
**ra et rb en même temp
*/
# define RRA_CMD 8
# define RRA "rra"

/*
**reverse rotate a - décale d’une position vers le bas tous les élemen
**. Le dernier élément devient le prem
*/

# define RRB_CMD 9
# define RRB "rrb"

/*
**reverse rotate b - décale d’une position vers le bas tous les élemen
**. Le dernier élément devient le emierrr
*/

# define RRR_CMD 10
# define RRR "rrr"

/*
**rra et rrb en même temps
*/

typedef	struct s_tab	t_tab;

typedef struct		s_lst
{
	int				nb;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_vari
{
	struct s_lst	*first_a;
	struct s_lst	*last_a;
	struct s_lst	*first_b;
	struct s_lst	*last_b;
	int				ret;
	int				count;
	char			*buf;
	t_tab			*tab_func;
}					t_vari;

struct				s_tab
{
	char			*command;
	void			(*f)(t_vari *);
};

void				ft_verif_command(char *command, t_tab *tab_func);
void				ft_swap_a(t_vari *var);
void				ft_swap_b(t_vari *var);
void				ft_swap_s(t_vari *var);
void				ft_push_a(t_vari *var);
void				ft_push_b(t_vari *var);
void				ft_rotate_a(t_vari *var);
void				ft_rotate_b(t_vari *var);
void				ft_rotate_r(t_vari *var);
void				ft_reverse_a(t_vari *var);
void				ft_reverse_b(t_vari *var);
void				ft_reverse_r(t_vari *var);
void				ft_exec_command(t_vari *var, t_tab *tab_func,
char *command);
void				ft_verif_tri(t_vari *var);
void				ft_phase_one(t_vari *var);
void				ft_phase_two(t_vari *var);
void				ft_exec(t_vari *var, char *name_cmd, int cmd);
void				ft_free_tab(char **tab);
long long			ft_altoi(const char *str);
t_lst				*ft_listnew(int nb);
t_lst				*ft_listlast(t_lst *lst);
int					ft_count_pile(t_lst *pile);
int					ft_init_tab_func(t_tab **tab);
int					ft_init_pile_a(t_lst **pile_a, char **av);
int					ft_list_pushback(t_lst **alst, t_lst *new);
int					ft_listadd(t_lst **alst, t_lst *new);
int					ft_verif_list(t_lst *pile_a);
int					ft_count_node(t_lst *lst);

#endif
