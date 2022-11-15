/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:10:14 by stelie            #+#    #+#             */
/*   Updated: 2022/04/19 20:42:22 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void	*content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (lst != NULL)
		size++;
	while (lst->next != NULL)
	{
		size++;
		lst = lst->next;
	}	
	return (size);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	list = NULL;
	while (lst)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (elem == NULL)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, elem);
		lst = lst->next;
	}
	return (lst);
}
