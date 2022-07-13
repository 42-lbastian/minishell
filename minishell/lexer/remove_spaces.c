#include "../include/minishell.h"

int		ft_count_spaces_flag(char *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	
	return (size);
}

void	ft_spaces_flag(char *str)
{
	int size;

	size = ft_count_spaces_flag(str);
}

void	ft_remove_spaces(t_list **lst)
{
	t_list *temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		if ((*lst)->type == FLAG)
			ft_spaces_flag((*lst)->content);
		//if ((*lst)->type == ARG)
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
}
