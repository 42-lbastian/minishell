/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:03 by stelie            #+#    #+#             */
/*   Updated: 2022/12/12 17:16:31 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief Updates the PWD and OLDPWD (in tab, not in env).
*/
static int	_update_wd(char **wd)
{
	char	*buf;

	buf = NULL;
	ft_free(wd[OLDPWD]);
	wd[OLDPWD] = ft_strdup(wd[PWD]);
	if (wd[OLDPWD] == NULL)
		return (EXIT_FAILURE);
	ft_free(wd[PWD]);
	buf = getcwd(buf, 0);
	wd[PWD] = ft_strdup(buf);
	ft_free(buf);
	if (wd[PWD] == NULL)
		return (EXIT_FAILURE);
	set_wd(wd);
	return (EXIT_SUCCESS);
}

/*
 * @brief Prints the error asked error for cd and returns EXIT_FAILURE.
*/
static int	_print_cd_error(char *arg, char *error)
{
	if (ft_strcmp(error, ERR_HOME_NOT_SET) == 0
		|| ft_strcmp(error, ERR_CD_ARGS) == 0)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(error, STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(error, STDERR_FILENO);
	}
	return (EXIT_FAILURE);
}

static int	_update_env_if(t_env *env, char **wd)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (ms_env_var_exists(env, "PWD") && ms_env_var_exists(env, "OLDPWD"))
	{
		exit_code = ms_env_update(&env, "PWD", wd[PWD]);
		if (exit_code == EXIT_SUCCESS)
			exit_code = ms_env_update(&env, "OLDPWD", wd[OLDPWD]);
	}
	else if (!(ms_env_var_exists(env, "PWD"))
		&& !(ms_env_var_exists(env, "OLDPWD")))
		exit_code = EXIT_SUCCESS;
	else if (ms_env_var_exists(env, "PWD")
		&& !(ms_env_var_exists(env, "OLDPWD")))
		exit_code = ms_env_update(&env, "PWD", wd[PWD]);
	else
		exit_code = ms_env_update(&env, "OLDPWD", wd[OLDPWD]);
	set_env(env);
	return (exit_code);
}

/*
 * @brief executes cd_builtin for given the path
 * @return Returns EXIT_SUCCESS or EXIT_FAILURE.
*/
static int	_cd_to_path(char *path, t_env *env)
{
	char	**wd;
	DIR		*dir;

	wd = get_wd();
	dir = opendir(path);
	if (dir == NULL)
		return (_print_cd_error(path, strerror(errno)));
	else if (closedir(dir) != EXIT_SUCCESS)
		return (_print_cd_error(path, strerror(errno)));
	else if (chdir(path) != EXIT_SUCCESS)
		return (_print_cd_error(path, strerror(errno)));
	if (_update_wd(wd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (_update_env_if(env, wd));
}

/*
 * @brief the cd builtin mandatory in the project
 * @param args: a string array where the first str is "cd"
 * @return Returns the err_code.
*/
int	cd_builtin(char	**args)
{
	t_env	*env;
	char	*home;
	int		exit_code;

	env = get_env();
	home = NULL;
	exit_code = EXIT_SUCCESS;
	if (args == NULL || env == NULL)
		return (EXIT_FAILURE);
	if (ft_str_arr_len(args) > 2)
		return (_print_cd_error(NULL, ERR_CD_ARGS));
	if (args[1] == NULL)
	{
		home = get_env_value(env, "HOME");
		if (home != NULL)
		{
			exit_code = _cd_to_path(home, env);
			ft_free(home);
		}
		else
			exit_code = _print_cd_error(NULL, ERR_HOME_NOT_SET);
	}
	else
		exit_code = _cd_to_path(args[1], env);
	return (exit_code);
}
