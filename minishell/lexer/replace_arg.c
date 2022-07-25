#include "../include/minishell.h"

int	ft_replace_arg(t_list **lst, t_List st)
{
	t_list	*temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		if ((*lst)->type == ARG)
		{
			if ((*lst)->content[0] != '\'')
			{
				(*lst)->content = ft_main_replace_env((*lst)->content, st);
				if (!(*lst)->content)
					return (1);
			}
		}
		(*lst)->content = ft_remove_quotes((*lst)->content);
		if (!(*lst)->content)
			return (1);
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
