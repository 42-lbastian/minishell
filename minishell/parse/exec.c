/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:47:29 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/28 16:43:39 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ms_strjoin_env(char *str1, char *str2, char c, int i)
{
	char	*dst;
	int		y;

	y = 0;
	dst = malloc(sizeof(char) * (ms_strlen(str1) + ms_strlen(str2) + 2));
	if (!dst)
		return (NULL);
	while (str1[i])
	{
		dst[y] = str1[i];
		y++;
		i++;
	}
	dst[y] = c;
	y++;
	i = 0;
	while (str2[i])
	{
		dst[y] = str2[i];
		y++;
		i++;
	}
	dst[y] = 0;
	return (dst);
}

int	ms_have_path(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (0);
	return (1);
}

void	ms_free_split(char **all_path)
{
	int	i;

	i = 0;
	while (all_path[i])
	{
		free(all_path[i]);
		i++;
	}
	free(all_path);
}

char	*ms_find_path(char *cmd, char **all_path)
{
	int		i;
	char	*good_path;

	i = 0;
	good_path = NULL;
	if (!all_path)
		return (NULL);
	if (cmd[0] == '.' || cmd[0] == '/')
	{
		ms_free_split(all_path);
		if (ms_have_path(cmd) == 0)
			return (cmd);
		else
			return (NULL);
	}
	else
	{
		while (all_path[i])
		{
			good_path = ms_strjoin_env(all_path[i], cmd, '/', 0);
			if (access(good_path, F_OK | X_OK) == 0)
				break ;
			else
			{
				free(good_path);
				good_path = NULL;
			}
			i++;
		}
	}
	ms_free_split(all_path);
	return (good_path);
}

int	ft_env_size(t_env *st)
{
	int	i;

	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
}

char	**ft_env_array(t_env *st)
{
	int		i;
	char	**env_arr;

	i = 0;
	env_arr = malloc(sizeof(char *) * (ft_env_size(st) + 1));
	env_arr[ft_env_size(st)] = NULL;
	while (st)
	{
		env_arr[i] = ms_strjoin_env(st->var, st->value, '=', 0);
		st = st->next;
		i++;
	}
	return (env_arr);
}

int	ft_exec_cmd(char *path, char **complete_cmd, char **env_arr)
{
	execve(path, complete_cmd, env_arr);
	return (1);
}

void	ms_main_exec_dumb(char **complete_cmd, t_env *st,
	int read, int write, int read2, int write2, int type)
{
	char	*path;
	int		pid;

	pid = fork();
	if (pid == -1)
	{
		printf("Error fork\n");
		return ;
	}
	else if (pid == 0)
	{
		path = ms_find_path(complete_cmd[0],
				ft_split(ms_find_var_path("PATH", st), ':'));
		if (!path)
		{
			ft_putstr_fd("File not found/access denied\n", STDERR_FILENO);
			return ;
		}
		//if (type == CMD_FILE_OUT || type == CMD_FILE_OUT_END)
		//	dup2(read2, STDIN_FILENO);
		//else
		dup2(read, STDIN_FILENO);
		if (type == CMD_MIDDLE || type == CMD_BEGIN || type == CMD_FILE_IN
			|| type == CMD_FILE_OUT || type == CMD_FILE_OUT_END)
			dup2(write2, STDOUT_FILENO);
		close(read2);
		close(write2);
		if (type == CMD_MIDDLE || type == CMD_END)
		{
			close(read);
			close(write);
		}
		if (type == CMD_FILE_IN || type == CMD_FILE_IN_END
			|| type == CMD_FILE_OUT || type == CMD_FILE_OUT_END)
			close(read);
		if (ft_exec_cmd(path, complete_cmd, ft_env_array(st)) == 1)
			ft_putstr_fd("Error exec\n", STDERR_FILENO);
	}
	else
	{
		if (type == CMD_END || type == CMD_MIDDLE)
		{
			close(read);
			close(write);
		}
		if (type == CMD_END || type == CMD_FILE_IN_END
			|| type == CMD_FILE_OUT_END || type == CMD_FILE_OUT)
		{
			close(read2);
			close(write2);
		}
		if (type == CMD_FILE_IN || type == CMD_FILE_IN_END
			|| type == CMD_FILE_OUT_END || type == CMD_FILE_OUT)
			close(read);
		waitpid(pid, NULL, 0);
	}
}

void	ms_main_exec_short(char **complete_cmd, t_env *st,
	int *pip, int *pip2, int type)
{
	char	*path;
	int		pid;

	pid = fork();
	if (pid == -1)
	{
		printf("Error fork\n");
		return ;
	}
	else if (pid == 0)
	{
		path = ms_find_path(complete_cmd[0],
				ft_split(ms_find_var_path("PATH", st), ':'));
		if (!path)
		{
			ft_putstr_fd("File not found/access denied\n", STDERR_FILENO);
			return ;
		}
		//if (type == CMD_FILE_OUT || type == CMD_FILE_OUT_END)
		//	dup2(pip2[0], STDIN_FILENO);
		//else
		dup2(pip[0], STDIN_FILENO);
		if (type == CMD_MIDDLE || type == CMD_BEGIN || type == CMD_FILE_IN
			|| type == CMD_FILE_OUT || type == CMD_FILE_OUT_END)
			dup2(pip2[1], STDOUT_FILENO);
		close(pip2[0]);
		close(pip2[1]);
		if (type == CMD_MIDDLE || type == CMD_END)
		{
			close(pip[0]);
			close(pip[1]);
		}
		if (type == CMD_FILE_IN || type == CMD_FILE_IN_END
			|| type == CMD_FILE_OUT || type == CMD_FILE_OUT_END)
			close(pip[0]);
		if (ft_exec_cmd(path, complete_cmd, ft_env_array(st)) == 1)
			ft_putstr_fd("Error exec\n", STDERR_FILENO);
	}
	else
	{
		if (type == CMD_END || type == CMD_MIDDLE)
		{
			close(pip[0]);
			close(pip[1]);
		}
		if (type == CMD_END || type == CMD_FILE_IN_END
			|| type == CMD_FILE_OUT_END || type == CMD_FILE_OUT)
		{
			close(pip2[0]);
			close(pip2[1]);
		}
		if (type == CMD_FILE_IN || type == CMD_FILE_IN_END
			|| type == CMD_FILE_OUT_END || type == CMD_FILE_OUT)
			close(pip[0]);
		waitpid(pid, NULL, 0);
	}
}

void	ms_exec_builtin(char **complete_cmd, t_env *st, int read, int write,
		int read2, int write2, int type)
{
	char	*path;
	int		pid;

	path = ms_find_path(complete_cmd[0],
		ft_split(ms_find_var_path("PATH", st), ':'));
	if (!path)
	{
		printf("Command not found\n");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		printf("Error fork\n");
		return ;
	}
	else if (pid == 0)
	{
		if (type == CMD_END)
			dup2(read, STDIN_FILENO);
		else if (type == CMD_BEGIN)
			dup2(write, STDOUT_FILENO);
		else
		{
			dup2(read, STDIN_FILENO);
			dup2(write2, STDOUT_FILENO);
		}
		if (!read2 || !write2)
		{
			close(read2);
			close(write2);
		}
		close(read);
		close(write);
		//if (ft_strcmp(complete_cmd[0], "cd") == 0)
		//{}	//cd(st, complete_cmd[1]);
		if (ft_strcmp(complete_cmd[0], "echo") == 0)
			echo_builtin(complete_cmd);
		if (ft_strcmp(complete_cmd[0], "cd") == 0)
			cd_builtin(complete_cmd);
		if (ft_strcmp(complete_cmd[0], "pwd") == 0)
			pwd_builtin();
		if (ft_strcmp(complete_cmd[0], "exit") == 0)
			exit_builtin(complete_cmd);
	}
	else
	{
		if (type == CMD_END || type == CMD_MIDDLE)
		{
			close(read);
			close(write);
		}
		if (type == CMD_BEGIN)
		{
			close(read2);
			close(write2);
		}
		waitpid(pid, NULL, 0);
	}
}

void	ms_is_builtin_short(char **complete_cmd, t_env *st, int *pipe, int *pipe2, int type)
{
	ms_main_exec_short(complete_cmd, st, pipe, pipe2, type);
}

void	ms_is_builtin_dumb(char **complete_cmd, t_env *st,
		int read, int write, int read2, int write2, int type)
{
	if (ft_strcmp(complete_cmd[0], "cd") == 0)
		ms_exec_builtin(complete_cmd, st, read, write, read2, write2, type);
	else if (ft_strcmp(complete_cmd[0], "exit") == 0)
		ms_exec_builtin(complete_cmd, st, read, write, read2, write2, type);
	else if (ft_strcmp(complete_cmd[0], "echo") == 0)
		ms_exec_builtin(complete_cmd, st, read, write, read2, write2, type);
	else if (ft_strcmp(complete_cmd[0], "pwd") == 0)
		ms_exec_builtin(complete_cmd, st, read, write, read2, write2, type);
	else
		ms_main_exec_dumb(complete_cmd, st, read, write, read2, write2, type);
}
