/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dup_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:39:40 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/08 16:21:40 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_set_dup2(int pip[2][2], int type)
{
	if (type == CMD_BEGIN || type == CMD_MIDDLE || type == CMD_FILE_OUT
		|| type == CMD_FILE_OUT_END || type == CMD_FILE_IN)
		dup2(pip[1][1], STDOUT_FILENO);
	if (type == CMD_MIDDLE || type == CMD_END || type == CMD_FILE_OUT
		|| type == CMD_FILE_OUT_END || type == CMD_FILE_IN
		|| type == CMD_FILE_IN_END || type == CMD_ALONE || type == CMD_HERE_DOC_END)
		dup2(pip[0][0], STDIN_FILENO);
}

void	ms_close_fd_fork(int pip[2][2], int type)
{
	if (type == CMD_MIDDLE || type == CMD_END || type == CMD_FILE_OUT
		|| type == CMD_FILE_OUT_END || type == CMD_HERE_DOC_END)
		close(pip[0][0]);
	if (type == CMD_MIDDLE || type == CMD_END || type == CMD_FILE_OUT
		|| type == CMD_FILE_OUT_END || type == CMD_HERE_DOC_END)
		close(pip[0][1]);
	if (type == CMD_BEGIN || type == CMD_MIDDLE || type == CMD_END
		|| type == CMD_ALONE || type == CMD_HERE_DOC_END)
		close(pip[1][0]);
	if (type == CMD_BEGIN || type == CMD_MIDDLE || type == CMD_END
		|| type == CMD_ALONE || type == CMD_FILE_OUT
		|| type == CMD_FILE_OUT_END || type == CMD_HERE_DOC_END)
		close(pip[1][1]);
}

void	ms_close_fd_parent(int pip[2][2], int type)
{
	if (type == CMD_MIDDLE || type == CMD_END || type == CMD_FILE_OUT_END
		|| type == CMD_FILE_IN || type == CMD_FILE_IN_END || type == CMD_HERE_DOC_END)
		close(pip[0][0]);
	if (type == CMD_MIDDLE || type == CMD_END || type == CMD_FILE_OUT_END || type == CMD_HERE_DOC_END)
		close(pip[0][1]);
	if (type == CMD_END || type == CMD_ALONE || type == CMD_FILE_IN_END || type == CMD_HERE_DOC_END)
		close(pip[1][0]);
	if (type == CMD_END || type == CMD_ALONE || type == CMD_FILE_OUT
		|| type == CMD_FILE_OUT_END || type == CMD_FILE_IN_END || type == CMD_HERE_DOC_END)
		close(pip[1][1]);
}
