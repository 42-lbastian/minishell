/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:21 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 11:27:12 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_lstadd(t_mslist **lst, t_mslist *new)
{
	if (!new)
		return (1);
	new->next = (*lst)->next;
	(*lst)->next = new;
	return (0);
}

t_mslist	*ms_lst_new_join(char *content, int type)
{
	t_mslist	*new;

	new = malloc(sizeof(t_mslist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = ms_strcpy(content);
	new->type = type;
	return (new);
}

t_mslist	*ms_lst_new(char *content, int type)
{
	t_mslist	*new;

	new = malloc(sizeof(t_mslist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	new->type = type;
	return (new);
}

t_mslist	*ms_lst_last(t_mslist *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ms_lstadd_back(t_mslist **lst, t_mslist *new)
{
	if (!new)
		return (1);
	if (lst && (*lst))
		ms_lst_last((*lst))->next = new;
	else
		(*lst) = new;
	return (0);
}
