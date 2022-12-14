/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:47:29 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/12 18:34:47 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ms_exec_parent(int pip[2][2], int pid, int type)
{
	int		status;

	set_err_code(0);
	ms_close_fd_parent(pip, type);
	waitpid(pid, &status, 0);
	set_err_code(WEXITSTATUS(status));
}

static int	ms_main_exec_short(char **complete_cmd, t_env *st,
	int pip[2][2], int type)
{
	char	*path;
	int		pid;

	path = ms_find_path(complete_cmd[0],
			ft_split(ms_find_var_path("PATH", st), ':'));
	if (!path)
		return (ft_putmsg_fd(ERR_PATH, STDERR_FILENO, EXIT_FAILURE));
	pid = fork();
	if (pid == -1)
		return (ft_putmsg_fd(ERR_FORK, STDERR_FILENO, EXIT_FAILURE));
	else if (pid == 0)
	{
		ms_set_dup2(pip, type);
		ms_close_fd_fork(pip, type);
		if (ft_exec_cmd(path, complete_cmd, ms_env_array(st)) == 1)
			exit(0);
	}
	else
	{
		ms_exec_parent(pip, pid, type);
		free(path);
	}
	return (EXIT_SUCCESS);
}

int	ms_is_builtin_short(char **complete_cmd, t_env *st, int pip[2][2], int type)
{
	if (ft_strcmp(complete_cmd[0], "cd") == 0)
		return (ms_exec_builtin(complete_cmd, pip, type));
	else if (ft_strcmp(complete_cmd[0], "echo") == 0)
		return (ms_exec_builtin(complete_cmd, pip, type));
	else if (ft_strcmp(complete_cmd[0], "pwd") == 0)
		return (ms_exec_builtin(complete_cmd, pip, type));
	else if (ft_strcmp(complete_cmd[0], "export") == 0)
		return (ms_exec_builtin(complete_cmd, pip, type));
	else if (ft_strcmp(complete_cmd[0], "unset") == 0)
		return (ms_exec_builtin(complete_cmd, pip, type));
	else if (ft_strcmp(complete_cmd[0], "env") == 0)
		return (ms_exec_builtin(complete_cmd, pip, type));
	else if (ft_strcmp(complete_cmd[0], "exit") == 0)
		return (ms_exec_builtin(complete_cmd, pip, type));
	else
		return (ms_main_exec_short(complete_cmd, st, pip, type));
}
