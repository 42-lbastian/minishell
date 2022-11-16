/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:10 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/16 20:09:13 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
