/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lst_parser_short.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <lbastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:20:38 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/29 15:38:48 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ms_read_file_in_short(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	int	fd;

	lst = lst->next;
	fd = open(lst->value.oper, O_RDONLY);
	if (fd == -1)
		return (ms_close_return(ERR_WRONG_FILE_IN, pip));
	pip[0][0] = fd;
	ms_read_lst_parser_short(lst->next, st, pip);
	return (EXIT_SUCCESS);
}

static int	ms_read_file_out_short(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	int	fd;

	lst = lst->next;
	pip[0][0] = pip[1][0];
	pip[0][1] = pip[1][1];
	if (lst->type == ARG_FILE_OUT_OVER)
		fd = open(lst->value.oper, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else
		fd = open(lst->value.oper, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		return (ms_close_return(ERR_WRONG_FILE_OUT, pip));
	pip[1][1] = fd;
	ms_read_lst_parser_short(lst->next, st, pip);
	return (EXIT_SUCCESS);
}

static int	ms_read_pipe_short(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	int	pip2[2][2];
	int	fd_pipe;

	if (lst->next && lst->prev)
	{
		fd_pipe = pipe(pip2[1]);
		if (fd_pipe == -1)
			return (ms_close_return(ERR_PIPE, pip));
		pip2[0][0] = pip[1][0];
		pip2[0][1] = pip[1][1];
		if (!lst->next->next && lst->next->type == CMD)
		{
			ms_is_builtin_short(lst->next->value.cmd, st, pip2, CMD_END);
			return (0);
		}
		else if (lst->next->type == CMD)
			ms_is_builtin_short(lst->next->value.cmd, st, pip2, CMD_MIDDLE);
		lst = lst->next;
		ms_read_lst_parser_short(lst->next, st, pip2);
	}
	else
		return (ms_close_return(ERR_PIPE_CMD, pip));
	return (EXIT_SUCCESS);
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
	if ((*lst) && (*lst)->prev && (*lst)->type == CMD && ((*lst)->prev->type
			== ARG_FILE_OUT_OVER || (*lst)->prev->type == ARG_FILE_OUT_APP))
	{
		if (!(*lst)->next)
			ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_FILE_OUT_END);
		else
			ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_FILE_OUT);
		(*lst) = (*lst)->next;
	}
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
	return (0);
}
