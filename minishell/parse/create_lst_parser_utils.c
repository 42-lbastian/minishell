/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_parser_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <lbastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:21:56 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/22 17:02:01 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ms_count_nb_cmd(t_list *lst)
{
	int i;

	i = 0;
	while (lst && lst->type == CMD)
	{
		i++;
		lst = lst->next;
		if (lst && lst->type != PIPE && lst->type != CMD && lst->next)
			lst = lst->next->next;
	}
	return (i);
}

int	ms_free_cmd(char ***cmd)
{
	int i;

	i = 0;
	while ((*cmd)[i])
	{
		free((*cmd)[i]);
		(*cmd)[i] = NULL;
		i++;
	}
	free((*cmd));
	(*cmd) = NULL;
	return (1);
}

int	ms_is_type_in_out(int type)
{
	if (type == FILE_IN || type == FILE_OUT_OVER || type == FILE_OUT_APP)\
		return (1);
	return (0);
}
