/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <lbastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:07:57 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/22 15:09:57 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ms_find_var_path(char *str, t_env *st)
{
	if (!str)
		return (NULL);
	while (st)
	{
		if (ft_strcmp(st->var, str) == 0)
			return (st->value);
		st = st->next;
	}
	return ("");
}

t_lst_parser	*ms_lst_parse_new(char **cmd, char *oper, int type)
{
	t_lst_parser	*new;

	new = malloc(sizeof(t_lst_parser));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	if (type == CMD)
		new->value.cmd = ms_strcpy_cmd(cmd);
	else
		new->value.oper = ft_strdup(oper);
	new->type = type;
	return (new);
}

t_lst_parser	*ms_lst_parse_last(t_lst_parser *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ms_lst_parse_add_back(t_lst_parser **lst, t_lst_parser *new)
{
	if (!new)
		return (1);
	if (lst && (*lst))
	{
		new->prev = ms_lst_parse_last((*lst));
		ms_lst_parse_last((*lst))->next = new;
	}
	else
		(*lst) = new;
	return (0);
}

int	ms_lst_parse_add_front(t_lst_parser **lst, t_lst_parser *new)
{
	if (!new)
		return (1);
	if (lst && (*lst))
	{
		(*lst)->prev = new;
		new->next = (*lst);
	}
	(*lst) = new;
	return (0);
}
