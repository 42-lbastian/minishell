/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:07:57 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 12:31:10 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	_free_strcpy_cmd(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free (ret[i]);
		i++;
	}
	free (ret);
}

static char	**ms_strcpy_cmd(char **arr)
{
	char	**ret;
	int		i;

	i = 0;
	while (arr[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	ret[i] = NULL;
	i = 0;
	while (arr[i])
	{
		ret[i] = ms_strcpy(arr[i]);
		if (!ret[i])
		{
			_free_strcpy_cmd(ret);
			return (NULL);
		}
		i++;
	}
	return (ret);
}

static t_lst_parser	*_lst_parse_last(t_lst_parser *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
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

int	ms_lst_p_addback(t_lst_parser **lst, t_lst_parser *new)
{
	if (!new)
		return (1);
	if (lst && (*lst))
	{
		new->prev = _lst_parse_last((*lst));
		_lst_parse_last((*lst))->next = new;
	}
	else
		(*lst) = new;
	return (0);
}
