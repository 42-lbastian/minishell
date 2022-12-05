/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:58:12 by stelie            #+#    #+#             */
/*   Updated: 2022/12/05 18:00:47 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	_env_update(t_env *env, char *var, char *new_value)
{
	t_env	*tmp;

	tmp = env;
	if (env == NULL || var == NULL)
		return (EXIT_FAILURE);
	while (tmp && tmp->var)
	{
		if (ft_strcmp(var, tmp->var) == 0)
		{
			if (tmp->value)
				ft_free(tmp->value);
			if (new_value == NULL)
				tmp->value = ft_strdup("");
			else
				tmp->value = ft_strdup(new_value);
			if (tmp->value == NULL)
				return (EXIT_FAILURE);
			else
				return (EXIT_SUCCESS);
		}
		tmp = tmp->next;
	}
	return (ms_add_back_env(&env, ms_new_env(var, new_value)));
}

int	_export_one(char *arg, t_env *env, char *var)
{
	char	*value;
	int		i;
	int		exit_code;

	value = NULL;
	exit_code = EXIT_SUCCESS;
	if (ft_incharset('=', arg) == false)
		return (exit_code);
	i = 0;
	var = ft_str_cut_before(arg, '=');
	if (var == NULL)
		exit_code = EXIT_FAILURE;
	else
	{
		value = ft_str_cut_after(arg, '=');
		exit_code = _env_update(env, var, value);
	}
	return (exit_code);
}

/*
 * @brief Copy the behavior of export with no args, adding 'declare -x'
 * in front of env variables.
 * man export says: "When no arguments are given, the results are unspecified"
*/
static	int	_print_export_no_args(t_env *env)
{
	while (env)
	{
		if (printf("declare -x %s=%s\n", env->var, env->value) == 0)
			return (EXIT_FAILURE);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}

int	export_builtin(char **args)
{
	t_env	*env;
	int		i;
	int		exit_code;
	char	*var;

	exit_code = EXIT_SUCCESS;
	i = 1;
	var = NULL;
	env = get_env();
	if (args[i] == NULL)
		return (_print_export_no_args(env));
	while (args[i] && exit_code == EXIT_SUCCESS)
	{
		if (_check_export_arg(args[i]) == true)
			exit_code = _export_one(args[i], env, var);
		i++;
	}
	return (EXIT_SUCCESS);
}
