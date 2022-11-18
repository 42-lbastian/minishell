/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:10 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/18 14:56:48 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list	*ms_lst_new_join(char *content, int type)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = ms_strcpy_2(content);
	new->type = type;
	return (new);
}

t_list	*ms_lst_new(char *content, int type)
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

t_list	*ms_lst_last(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ms_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return (1);
	if (lst && (*lst))
		ms_lst_last((*lst))->next = new;
	else
		(*lst) = new;
	return (0);
}
