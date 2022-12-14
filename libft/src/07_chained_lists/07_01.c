/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:10:14 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 13:08:04 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_LSTLAST
 * FT_LSTNEW
 * FT_LSTSIZE
 * FT_LSTMAP
*/

/*
 * @brief  --  NOT DOCUMENTED
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
 * @brief  --  NOT DOCUMENTED
*/
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

/*
 * @brief  --  NOT DOCUMENTED
*/
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

/*
 * @brief  --  NOT DOCUMENTED
*/
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
