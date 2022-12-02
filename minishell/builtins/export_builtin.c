/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:58:12 by stelie            #+#    #+#             */
/*   Updated: 2022/12/02 15:25:18 by stelie           ###   ########.fr       */
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

int	_export_one(char *arg, t_env *env)
{
	char	*var;
	char	*value;
	int		i;

	i = 0;
	var = NULL;
	value = NULL;
	var = ft_str_cut_before(arg, '=');
	if ((arg[ft_strlen(var)] && arg[ft_strlen(var)] == '='))
	{
		value = ft_str_cut_after(arg, '=');
		return (_env_update(env, var, value));
	}
	return (EXIT_SUCCESS);
}

int	_print_export_no_args(t_env *env)
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

	i = 1;
	env = get_env();
	if (args[i] == NULL || ft_strlen(args[i]) < 1)
		return (_print_export_no_args(env));
	while (args[i])
	{
		if (_export_one(args[i], env) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
