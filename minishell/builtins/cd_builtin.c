/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:03 by stelie            #+#    #+#             */
/*   Updated: 2022/12/05 18:48:43 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	_print_cd_error(char *arg, char *error)
{
	if (ft_strcmp(error, ERR_HOME_NOT_SET) == 0)
		ft_putstr_fd(error, STDERR_FILENO);
	else
	{
		ft_putstr_fd("cd :", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(error, STDERR_FILENO);
	}
	return (EXIT_FAILURE);
}

/*
 * @brief initialisation if the t_wd structure.
*/
static void	_init_pwd(t_env *env, t_wd **wd)
{
	(*wd) = malloc(sizeof(t_wd));
	if ((*wd) == NULL)
		return ;
	(*wd)->cwd = NULL;
	(*wd)->home = get_env_value(env, "HOME");
	(*wd)->pwd = get_env_value(env, "PWD");
	(*wd)->oldpwd = get_env_value(env, "OLDPWD");
}

/*
 * @brief Exits and frees the wd structures.
*/
static int	_exit_cd_builtin(t_wd *wd, int exit_code)
{
	if (wd)
	{
		if (wd->home)
			ft_free(wd->home);
		if (wd->cwd)
			ft_free(wd->cwd);
		if (wd->pwd)
			ft_free(wd->pwd);
		if (wd->oldpwd)
			ft_free(wd->oldpwd);
		ft_free(wd);
	}
	return (exit_code);
}

/*
 * @brief executes cd_builtin for given the path
 * @return Returns EXIT_SUCCESS or EXIT_FAILURE.
*/
static int	_cd_to_path(char *path, t_env *env)
{
	t_wd	*wd;
	DIR		*dir;

	_init_pwd(env, &wd);
	dir = opendir(path);
	if (dir == NULL)
		return (_exit_cd_builtin(wd, EXIT_FAILURE));
	else if (closedir(dir) != EXIT_SUCCESS)
		return (_exit_cd_builtin(wd, EXIT_FAILURE));
	else if (chdir(path) != EXIT_SUCCESS)
		return (_exit_cd_builtin(wd, EXIT_FAILURE));
	if (ms_env_update(env, "OLDPWD", wd->pwd) == EXIT_FAILURE)
		return (_exit_cd_builtin(wd, EXIT_FAILURE));
	wd->cwd = getcwd(wd->cwd, 0);
	if (ms_env_update(env, "PWD", wd->cwd) == EXIT_FAILURE)
		return (_exit_cd_builtin(wd, EXIT_FAILURE));
	set_env(env);
	return (_exit_cd_builtin(wd, EXIT_SUCCESS));
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
