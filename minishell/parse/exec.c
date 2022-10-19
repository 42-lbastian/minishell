#include "../include/minishell.h"

char	*ft_strjoin_env(char *str1, char *str2, char c)
{
	char	*dst;
	int		i;
	int		y;

	i = 0;
	y = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 2));
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

int	ft_have_path(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (0);
	printf("File not found/access denied\n");
	return (1);
}

char	*ft_find_path(char *cmd, char **all_path)
{
	int		i;
	char	*good_path;

	i = 0;

	// FREE ALL_PATH (split)
	if (!all_path)
		return (NULL);
	if (cmd[0] == '.' || cmd[0] == '/')
	{
		if (ft_have_path(cmd) == 0)
			return (cmd);
		else
			return (NULL);
	}
	else
	{
		while (all_path[i])
		{
			good_path = ft_strjoin_env(all_path[i], cmd, '/');
			if (access(good_path, F_OK | X_OK) == 0)
				return (good_path);
			else
			{
				free(good_path);
				good_path = NULL;
			}
			i++;
		}
	}
	return (NULL);
}

int		ft_env_size(t_List st)
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

char	**ft_env_array(t_List st)
{
	int		i;
	char	**env_arr;

	i = 0;
	env_arr = malloc(sizeof(char *) * (ft_env_size(st) + 1));
	env_arr[ft_env_size(st)] = NULL;
	while (st)
	{
		env_arr[i] = ft_strjoin_env(st->var, st->value, '=');
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

void	ft_main_exec(char **complete_cmd, t_List st, int *pip, int type)
{
	char	*path;
	int		pid;
	
	path = ft_find_path(complete_cmd[0], ft_split(ft_find_var_path("PATH", st), ':'));
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
			dup2(pip[0], STDIN_FILENO);
		else if (type == CMD_BEGIN)
			dup2(pip[1], STDOUT_FILENO);
		else
		{
			dup2(pip[0], STDIN_FILENO);
			dup2(pip[1], STDOUT_FILENO);
		}
		close(pip[0]);
		close(pip[1]);
		if (ft_exec_cmd(path, complete_cmd, ft_env_array(st)) == 1)
			ft_putstr_fd("Error exec\n", STDERR_FILENO);
			//printf("Error exec\n");
	}
	else
		waitpid(pid, NULL, 0);
}
