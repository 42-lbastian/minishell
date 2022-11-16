/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:21 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/16 20:09:24 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_lstadd(t_list **lst, t_list *new)
{
	if (!new)
		return (1);
	new->next = (*lst)->next;
	(*lst)->next = new;
	return (0);
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

char	*ft_find_var(char *str, t_env *st)
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
