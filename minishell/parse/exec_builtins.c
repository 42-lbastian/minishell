/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:31:13 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/12 16:36:26 by lbastian         ###   ########.fr       */
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
}

int	ms_exec_builtin_env(char **complete_cmd, int pip[2][2], int type)
{
	ms_close_fd_parent(pip, type);
	if (ft_strcmp(complete_cmd[0], "cd") == 0)
		set_err_code(cd_builtin(complete_cmd));
	if (ft_strcmp(complete_cmd[0], "export") == 0)
		set_err_code(export_builtin(complete_cmd));
	if (ft_strcmp(complete_cmd[0], "unset") == 0)
		set_err_code(unset_builtin(complete_cmd));
	if (ft_strcmp(complete_cmd[0], "exit") == 0)
		exit_builtin(complete_cmd);
	return (EXIT_SUCCESS);
}

int	ms_exec_builtin_fork(char **complete_cmd, int pip[2][2], int type)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (ft_putmsg_fd(ERR_FORK, STDERR_FILENO, EXIT_FAILURE));
	else if (pid == 0)
	{
		ms_set_dup2(pip, type);
		ms_close_fd_fork(pip, type);
		ms_exec_builtin_loop(complete_cmd);
		exit (0);
	}
	else
	{
		set_err_code(0);
		ms_close_fd_parent(pip, type);
		waitpid(pid, &status, 0);
		set_err_code(WEXITSTATUS(status));
	}
	return (EXIT_SUCCESS);
}
