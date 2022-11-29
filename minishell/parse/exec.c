/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:47:29 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/29 12:30:07 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_exec_cmd(char *path, char **complete_cmd, char **env_arr)
{
	if (!env_arr)
		return (ft_putmsg_fd(ERR_MALLOC_ENV_ARR, STDERR_FILENO, EXIT_FAILURE));
	execve(path, complete_cmd, env_arr);
	return (1);
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
		ms_close_fd_parent(pip, type);
		waitpid(pid, NULL, 0);
		free(path);
	}
	return (EXIT_SUCCESS);
}

static void	ms_exec_builtin_loop(char **complete_cmd)
{
	if (ft_strcmp(complete_cmd[0], "echo") == 0)
		echo_builtin(complete_cmd);
	if (ft_strcmp(complete_cmd[0], "cd") == 0)
		cd_builtin(complete_cmd);
	if (ft_strcmp(complete_cmd[0], "pwd") == 0)
		pwd_builtin();
	if (ft_strcmp(complete_cmd[0], "exit") == 0)
		exit_builtin(complete_cmd);
}

static int	ms_exec_builtin_short(char **complete_cmd, int pip[2][2], int type)
{
	int		pid;

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
		ms_close_fd_parent(pip, type);
		waitpid(pid, NULL, 0);
	}
	return (EXIT_SUCCESS);
}

int	ms_is_builtin_short(char **complete_cmd, t_env *st, int pip[2][2], int type)
{
	if (ft_strcmp(complete_cmd[0], "cd") == 0)
		return (ms_exec_builtin_short(complete_cmd, pip, type));
	else if (ft_strcmp(complete_cmd[0], "exit") == 0)
		return (ms_exec_builtin_short(complete_cmd, pip, type));
	else if (ft_strcmp(complete_cmd[0], "echo") == 0)
		return (ms_exec_builtin_short(complete_cmd, pip, type));
	else if (ft_strcmp(complete_cmd[0], "pwd") == 0)
		return (ms_exec_builtin_short(complete_cmd, pip, type));
	else
		return (ms_main_exec_short(complete_cmd, st, pip, type));
}
