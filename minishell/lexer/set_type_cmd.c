#include "../include/minishell.h"

int	ft_set_type_cmd(t_list **lst)
{
	t_list *temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		if ((*lst)->next && (*lst)->next->type == CMD && (*lst)->type == FILE_IN)
			(*lst)->next->type = ARG_FILE_IN;
		else if ((*lst)->next && (*lst)->next->type == CMD && (*lst)->type == FILE_OUT_OVER)
			(*lst)->next->type = ARG_FILE_OUT_OVER;
		else if ((*lst)->next && (*lst)->next->type == CMD && (*lst)->type == FILE_OUT_APP)
			(*lst)->next->type = ARG_FILE_OUT_APP;
		else if ((*lst)->next && (*lst)->next->type == CMD && (*lst)->type == HERE_DOC)
			(*lst)->next->type = LIMITOR;
		else if ((*lst)->next && (*lst)->next->type >= PIPE && (*lst)->type >= PIPE)
		{
			(*lst) = temp;
			return (1);
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
