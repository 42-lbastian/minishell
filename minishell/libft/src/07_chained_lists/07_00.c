/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:16:09 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 13:07:07 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_LSTADD_BACK  --  NOT DOCUMENTED
 * FT_LSTADD_FRONT  --  NOT DOCUMENTED
 * FT_LSTCLEAR  --  NOT DOCUMENTED
 * FT_LSTDELONE  --  NOT DOCUMENTED
 * FT_LSTITER  --  NOT DOCUMENTED
*/

/*
 * @brief  --  NOT DOCUMENTED
*/
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*start;

	new->next = NULL;
	if (*alst == NULL)
		*alst = new;
	else
	{
		start = *alst;
		while (start->next != NULL)
			start = start->next;
		start->next = new;
	}
}

/*
 * @brief  --  NOT DOCUMENTED
*/
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (*alst == NULL)
		new->next = NULL;
	*alst = new;
}

/*
 * @brief  --  NOT DOCUMENTED
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && del)
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			*lst = tmp->next;
			ft_lstdelone(tmp, (*del));
			tmp = *lst;
		}
		*lst = NULL;
	}
}

/*
 * @brief  --  NOT DOCUMENTED
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del && lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

/*
 * @brief  --  NOT DOCUMENTED
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && (*f))
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
