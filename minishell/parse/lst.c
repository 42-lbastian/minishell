#include "../include/minishell.h"

char	*ft_find_var_path(char *str, t_List st)
{
	if (!str)
		return (NULL);
	while (st)
	{
		if (ft_strcmp_2(st->var, str) == 0)
			return (st->value);
		st = st->next;
	}
	return ("");
}

t_lst_cmd	*ft_lst_parse_new(char **cmd, char *oper, int type)
{
	t_lst_cmd	*new;

	new = malloc(sizeof(t_lst_cmd));
	if (!new)
		return (NULL);
	new->next = NULL;
	if (type == CMD)
		new->value.cmd = cmd;
	else
		new->value.oper = oper;
	new->type = type;
	return (new);
}

t_lst_cmd	*ft_lst_parse_last(t_lst_cmd *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lst_parse_add_back(t_lst_cmd **lst, t_lst_cmd *new)
{
	if (!new)
		return (1);
	if (lst && (*lst))
		ft_lst_parse_last((*lst))->next = new;
	else
		(*lst) = new;
	return (0);
}

void	ft_print_lst_parse(t_lst_cmd *lst)
{
	int i;

	while (lst)
	{
		i = 0;
		if (lst->type == CMD)
		{
			while (lst->value.cmd[i])
			{
				printf("%s\t", lst->value.cmd[i]);
				i++;
			}
			printf("\n");
		}
		else
			printf("%s\n", lst->value.oper);
		lst = lst->next;
	}
}
