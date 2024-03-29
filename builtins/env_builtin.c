/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:43:58 by stelie            #+#    #+#             */
/*   Updated: 2022/12/09 18:09:32 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @name _env_err_msg()
 * @brief Print the error message and returns EXIT_FAILURE.
*/
int	_env_err_msg(char *name, char *err_msg)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(err_msg, 2);
	return (EXIT_FAILURE);
}

/*
 * @name: _ms_print_env()
 * @brief Sert à afficher le t_env cree (equivault a 'env')
*/
int	_ms_print_env(t_env *ms_env)
{
	while (ms_env)
	{
		printf("%s=%s\n", ms_env->var, ms_env->value);
		ms_env = ms_env->next;
	}
	return (EXIT_SUCCESS);
}

/*
 * @brief the env builtin mandatory in the project
 * @param args: a string array where the first str is "env"
 * @return Returns the err_code.
*/
int	env_builtin(char **args)
{
	t_env	*env;

	env = get_env();
	if (!env)
		return (EXIT_FAILURE);
	if (args && args[1] != NULL)
	{
		if (access(args[1], F_OK) != 0)
			return (_env_err_msg(args[1], ERR_NO_SUCH));
		else if (access(args[1], R_OK) != 0)
			return (_env_err_msg(args[1], ERR_ENV_PERM));
		else
			return (_env_err_msg(args[1], ERR_ENV_OPTION));
	}
	return (_ms_print_env(env));
}
