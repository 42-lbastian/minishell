/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:31:13 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/12 18:35:06 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ms_exec_builtin_loop(char **complete_cmd)
{
	if (ft_strcmp(complete_cmd[0], "echo") == 0)
		echo_builtin(complete_cmd);
	if (ft_strcmp(complete_cmd[0], "pwd") == 0)
		pwd_builtin();
	if (ft_strcmp(complete_cmd[0], "env") == 0)
		env_builtin(complete_cmd);
	if (ft_strcmp(complete_cmd[0], "cd") == 0)
		set_err_code(cd_builtin(complete_cmd));
	if (ft_strcmp(complete_cmd[0], "export") == 0)
		set_err_code(export_builtin(complete_cmd));
	if (ft_strcmp(complete_cmd[0], "unset") == 0)
		set_err_code(unset_builtin(complete_cmd));
	if (ft_strcmp(complete_cmd[0], "exit") == 0)
		exit_builtin(complete_cmd);

}

int	ms_exec_builtin(char **complete_cmd, int pip[2][2], int type)
{
	int	fd_save_out;
	int	fd_save_in;

	fd_save_out = dup(STDOUT_FILENO);
	fd_save_in = dup(STDIN_FILENO);
	ms_set_dup2(pip, type);
	ms_exec_builtin_loop(complete_cmd);
	dup2(fd_save_out, STDOUT_FILENO);
	dup2(fd_save_in, STDIN_FILENO);
	close(fd_save_out);
	close(fd_save_in);
	ms_close_fd_parent(pip, type);
	return (EXIT_SUCCESS);
}
