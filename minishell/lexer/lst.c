#include "../include/minishell.h"

t_list	*ft_lst_new_join(char *content, int type)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = ft_strcpy_2(content);
	new->type = type;
	return (new);
}

t_list	*ft_lst_new(char *content, int type)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	new->type = type;
	return (new);
}

t_list	*ft_lst_last(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return (1);
	if (lst && (*lst))
		ft_lst_last((*lst))->next = new;
	else
		(*lst) = new;
	return (0);
}

int	ft_lstadd(t_list **lst, t_list *new)
{
	if (!new)
		return (1);
	new->next = (*lst)->next;
	(*lst)->next = new;
	return (0);
}

void	ft_print_lst(t_list *lst)
{
	while (lst)
	{
		if (lst->type == PIPE)
			printf("{%s}\t[|]\n", lst->content);
		if (lst->type == FILE_IN)
			printf("{%s}\t[<]\n", lst->content);
		if (lst->type == FILE_OUT_OVER)
			printf("{%s}\t[>]\n", lst->content);
		if (lst->type == FILE_OUT_APP)
			printf("{%s}\t[>>]\n", lst->content);
		if (lst->type == HERE_DOC)
			printf("{%s}\t[<<]\n", lst->content);
		if (lst->type == CMD)
			printf("{%s}\t[CMD]\n", lst->content);
		if (lst->type == ARG_FILE_IN)
			printf("{%s}\t[ARG_FILE_IN]\n", lst->content);
		if (lst->type == ARG_FILE_OUT_OVER)
			printf("{%s}\t[ARG_FILE_OUT_OVER]\n", lst->content);
		if (lst->type == ARG_FILE_OUT_APP)
			printf("{%s}\t[ARG_FILE_OUT_APP]\n", lst->content);
		if (lst->type == LIMITOR)
			printf("{%s}\t[LIMITOR]\n", lst->content);
		lst = lst->next;
	}
}

int	ft_lst_size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

char	*ft_get_lst_str_index(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (lst && i < index)
	{
		i++;
		lst = lst->next;
	}
	return (lst->content);
}

char	*ft_find_var(char *str, t_List st)
{
	if (!str)
		return (NULL);
	while (st)
	{
		if (ft_strcmp_2(st->var, str) == 0)
		{
			free(str);
			return (st->value);
		}
		st = st->next;
	}
	free(str);
	return ("");
}
