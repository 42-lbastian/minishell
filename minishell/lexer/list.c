#include "../include/minishell.h"

t_list	*ft_lst_new(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->next = NULL;
	new->content = content;
	return (new);
}

t_list	*ft_lst_last(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && (*lst))
		ft_lst_last((*lst))->next = new;
	else
		(*lst) = new;
}

void	ft_print_lst(t_list *lst)
{
	while (lst)
	{
		printf("|%s|\n", lst->content);
		lst = lst->next;
	}
}

int	ft_lst_size(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

char *ft_get_lst_str_index(t_list *lst, int index)
{
	int i;

	i = 0;
	while (lst && i < index)
	{
		i++;
		lst = lst->next;
	}
	return (lst->content);
}
