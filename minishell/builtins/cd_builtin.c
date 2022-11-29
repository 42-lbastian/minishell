/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:03 by stelie            #+#    #+#             */
/*   Updated: 2022/11/29 15:37:34 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	if (exit_code == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	perror("Error");
	return (EXIT_FAILURE);
}

/*
 * @brief the cd builtin mandatory in the project
 * @param args: a string array where the first str is "cd"
 * @return Returns the err_code.
*/
static int	_cd_home(t_env *env)
{
	int		err_code;
	t_wd	*wd;

	err_code = EXIT_SUCCESS;
	wd = NULL;
	_init_pwd(env, &wd);
	if (wd->home == NULL || ft_strlen(wd->home) == 0)
		err_code = ft_putmsg_fd(ERR_HOME_NOT_SET, STDERR_FILENO, EXIT_FAILURE);
	else if (chdir(wd->home) != 0)
	{
		ft_free(wd->home);
		return (_exit_cd_builtin(wd, EXIT_FAILURE));
	}
	if (err_code == EXIT_SUCCESS)
		err_code = ms_env_update(env, "OLDPWD", wd->pwd);
	if (err_code == EXIT_SUCCESS)
		err_code = ms_env_update(env, "PWD", wd->home);
	set_env(env);
	return (_exit_cd_builtin(wd, err_code));
}

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

int	cd_builtin(char	**args)
{
	t_env	*env;

	env = get_env();
	if (args == NULL || env == NULL)
		return (EXIT_FAILURE);
	if (ft_str_arr_len(args) > 2)
		return (ft_putmsg_fd(ERR_CD_ARGS, STDERR_FILENO, EXIT_FAILURE));
	if (args[1] == NULL)
		return (_cd_home(env));
	else
		return (_cd_to_path(args[1], env));
	return (EXIT_SUCCESS);
}
