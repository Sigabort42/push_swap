#include "push_swap.h"

void			ft_list_pushback(t_lst **alst, t_lst *new)
{
	t_lst		*tmp;

	if (!(*alst))
	{
		if (!(*alst = (t_lst*)malloc(sizeof(t_lst))))
			exit(EXIT_FAILURE);
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

static void		ft_listadd(t_lst **alst, t_lst *new)
{
	if (!(*alst))
	{
		if (!(*alst = (t_lst*)malloc(sizeof(t_lst))))
			exit(EXIT_FAILURE);
		*alst = new;
		return ;
	}
	(*alst)->prev = new;
	new->next = *alst;
	*alst = new;
}

t_lst			*ft_listnew(int nb)
{
	t_lst		*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		exit(EXIT_FAILURE);
	new->nb = nb;
	new->next = 0;
	new->prev = 0;
	return (new);
}

static void		ft_verif_list(t_lst *pile_a)
{
	t_lst		*tmp;
	t_lst		*tmp2;

	tmp = pile_a;
	tmp2 = pile_a->next;
	while (tmp->next)
	{
		while (tmp2)
		{
			if (tmp->nb == tmp2->nb)
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
}

void			ft_init_pile_a(t_lst **pile_a, char **av)
{
	int		i;
	int		j;
	char		**tab_nb;
	long long	nb;

	i = 1;
	j = 0;
	*pile_a = 0;
	while (av[i])
	{
		tab_nb = ft_strsplit(av[i], ' ');
		while (tab_nb[j] && (ft_isdigit(tab_nb[j][0]) || tab_nb[j][0] == '-'))
		{
			nb = ft_altoi(tab_nb[j++]);
			if (nb < -2147483648 || nb > 2147483647)
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			ft_listadd(pile_a, ft_listnew(nb));
		}
		ft_verif_list(*pile_a);
		if (tab_nb[j] && (!ft_isdigit(tab_nb[j][0])) && tab_nb[j][0] != '-')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		j = 0;
		i++;
	}
}
