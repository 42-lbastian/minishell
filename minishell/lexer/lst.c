/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:21 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/12 18:01:19 by lbastian         ###   ########.fr       */
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

int	ms_lst_size(t_mslist *lst)
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

char	*ms_get_lst_str_index(t_mslist *lst, int index)
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

char	*ms_find_var(char *str, t_env *st)
{
	if (!str)
		return (NULL);
	if (ft_strcmp(str, "?") == 0)
	{
		free(str);
		return (ft_itoa(get_err_code()));
	}
	while (st)
	{
		if (ft_strcmp(st->var, str) == 0)
		{
			free(str);
			return (ft_strdup(st->value));
		}
		st = st->next;
	}
	free(str);
	return (ft_strdup(""));
}
