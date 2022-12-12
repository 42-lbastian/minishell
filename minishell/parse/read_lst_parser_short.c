/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lst_parser_short.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <lbastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:20:38 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/12 16:43:13 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ms_check_cmd_2(t_lst_parser **lst, t_env *st, int pip[2][2])
{
	if ((*lst) && (*lst)->prev && (*lst)->type == CMD && ((*lst)->prev->type
			== ARG_FILE_OUT_OVER || (*lst)->prev->type == ARG_FILE_OUT_APP))
	{
		if (!(*lst)->next)
			ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_FILE_OUT_END);
		else
			ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_FILE_OUT);
		(*lst) = (*lst)->next;
	}
	if ((*lst) && (*lst)->prev && (*lst)->type == CMD && (*lst)->prev->type
		== LIMITOR)
	{
		if (!(*lst)->next)
			ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_HERE_DOC_END);
		else
			ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_HERE_DOC);
		(*lst) = (*lst)->next;
	}
}

static void	ms_check_cmd(t_lst_parser **lst, t_env *st, int pip[2][2])
{
	if ((*lst) && (*lst)->type == CMD && pip[0][0] == -1)
	{
		ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_BEGIN);
		(*lst) = (*lst)->next;
	}
	if ((*lst) && (*lst)->prev && (*lst)->prev->type
		== ARG_FILE_IN && (*lst)->type == CMD)
	{
		if (!(*lst)->next)
			ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_FILE_IN_END);
		else
			ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_FILE_IN);
		(*lst) = (*lst)->next;
	}
	ms_check_cmd_2(lst, st, pip);
}

int	ms_read_lst_parser_short(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	if (lst && lst->prev == NULL && lst->next == NULL && lst->type == CMD)
	{
		ms_is_builtin_short(lst->value.cmd, st, pip, CMD_ALONE);
		return (EXIT_SUCCESS);
	}
	ms_check_cmd(&lst, st, pip);
	if (lst && lst->next && lst->type == CMD)
		lst = lst->next;
	if (lst && lst->type == PIPE)
		if (ms_read_pipe_short(lst, st, pip) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	if (lst && lst->type == FILE_IN)
		if (ms_read_file_in_short(lst, st, pip) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	if (lst && (lst->type == FILE_OUT_OVER || lst->type == FILE_OUT_APP))
		if (ms_read_file_out_short(lst, st, pip) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	if (lst && lst->type == HERE_DOC)
		if (ms_here_doc(lst->next, st, pip) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (0);
}
