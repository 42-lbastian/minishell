#include "../include/minishell.h"

void	ft_free_lst(t_list **lst)
{
	t_list *temp;

	while ((*lst) && (*lst)->next)
	{
		temp = ((*lst)->next);
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
