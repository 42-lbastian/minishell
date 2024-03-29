#include "../include/minishell.h"

void	ft_free_all(t_list **lst)
{
	ft_free_lst(lst);
}

void	ft_free_lst(t_list **lst)
{
	t_list	*temp;

	while ((*lst) && (*lst)->next)
	{
		temp = ((*lst)->next);
		if ((*lst)->content)
			free((*lst)->content);
		free((*lst));
		(*lst) = temp;
	}
	if ((*lst))
	{
		free((*lst)->content);
		free((*lst));
	}
	(*lst) = NULL;
}
