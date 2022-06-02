#include "../include/minishell.h"

t_list	*ft_lst_new(char *content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->next = NULL;
//	new->content = ft_strcpy(content);
	new->content = content;
	return (new);
}

t_list *ft_lst_last(t_list *lst)
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
	while (lst->next)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	printf("%s\n", lst->content);
}
