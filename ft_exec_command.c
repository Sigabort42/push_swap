#include "push_swap.h"

void	ft_exec_command(t_vari *var, t_tab *tab_func, char *command)
{
	int	i;

	i = 0;
	while (tab_func[i].command)
	{
		if (!ft_strcmp(command, tab_func[i].command))
		{
			tab_func[i].f(var);
			return ;
		}
		i++;
	}
}
