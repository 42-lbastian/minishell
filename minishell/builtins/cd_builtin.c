/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:03 by stelie            #+#    #+#             */
/*   Updated: 2022/11/29 14:30:31 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief initialisation if the t_wd structure.
*/
static void	_init_pwd(t_env *env, t_wd **var)
{
	(*var) = malloc(sizeof(t_wd));
	if ((*var) == NULL)
		return ;
	(*var)->cwd = NULL;
	(*var)->home = get_env_value(env, "HOME");
	(*var)->pwd = get_env_value(env, "PWD");
	(*var)->oldpwd = get_env_value(env, "OLDPWD");
}

/*
 * @brief Exits and frees the wd structures.
*/
static int	_exit_cd_builtin(t_wd *var, int exit_code)
{
	if (var)
	{
		if (var->home)
			ft_free(var->home);
		if (var->cwd)
			ft_free(var->cwd);
		if (var->pwd)
			ft_free(var->pwd);
		if (var->oldpwd)
			ft_free(var->oldpwd);
		ft_free(var);
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
	return (EXIT_SUCCESS);
}
