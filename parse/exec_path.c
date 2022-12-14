/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:40:05 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 12:10:57 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ms_env_array(t_env *st)
{
	int		i;
	char	**env_arr;

	i = 0;
	env_arr = malloc(sizeof(char *) * (ms_env_size(st) + 1));
	if (!env_arr)
		return (NULL);
	env_arr[ms_env_size(st)] = NULL;
	while (st)
	{
		env_arr[i] = ms_strjoin_env(st->var, st->value, '=', 0);
		if (!env_arr[i])
		{
			ft_str_arr_free(env_arr);
			return (NULL);
		}
		st = st->next;
		i++;
	}
	return (env_arr);
}

static int	_have_path(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (0);
	if (access(cmd, F_OK) == -1)
		set_err_code(127);
	else if (access(cmd, X_OK) == -1)
		set_err_code(126);
	return (1);
}

static void	_set_err_path(char *good_path)
{
	if (access(good_path, F_OK) == -1)
		set_err_code(127);
	else if (access(good_path, X_OK) == -1)
		set_err_code(126);
}

static char	*_find_path_loop(char *cmd, char **all_path)
{
	char	*good_path;
	int		i;

	i = 0;
	good_path = NULL;
	while (all_path[i])
	{
		good_path = ms_strjoin_env(all_path[i], cmd, '/', 0);
		if (!good_path)
			return (NULL);
		if (access(good_path, F_OK | X_OK) == 0)
		{
			set_err_code(0);
			break ;
		}
		else
		{
			_set_err_path(good_path);
			free(good_path);
			good_path = NULL;
		}
		i++;
	}
	return (good_path);
}

char	*ms_find_path(char *cmd, char **all_path)
{
	char	*good_path;

	good_path = NULL;
	if (!all_path)
		return (NULL);
	if (cmd[0] == '.' || cmd[0] == '/')
	{
		ms_free_split(all_path);
		if (_have_path(cmd) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	else
		good_path = _find_path_loop(cmd, all_path);
	ms_free_split(all_path);
	return (good_path);
}
