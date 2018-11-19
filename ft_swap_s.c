#include "push_swap.h"

void	ft_swap_s(t_vari *var)
{
	var->tab_func[0].f(var);
	var->tab_func[1].f(var);
}
