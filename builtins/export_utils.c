/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:30:21 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 10:14:49 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief Copy the behavior of export with no args, adding 'declare -x'
 * in front of env variables.
 * man export says: "When no arguments are given, the results are unspecified"
*/
static void	_print_export_no_args(t_env *env, char **var)
{
	int		i;
	char	*value;

	i = 0;
	value = NULL;
	while (var[i])
	{
		value = ms_get_env_value(env, var[i]);
		printf("declare -x %s=;%s\n", var[i], value);
		ft_free(value);
		i++;
	}
}

/*
 * Does alphabetical sorting for the variables in env.
*/
static void	_sort(t_env *env, char **var, int len)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(var[i], var[j]) > 0)
			{
				tmp = var[i];
				var[i] = var[j];
				var[j] = tmp;
			}
			j++;
		}
		i++;
	}
	_print_export_no_args(env, var);
}

/*
 * @brief Gets the number of variables in environnement.
*/
static int	_env_len(t_env *env)
{
	int		len;

	len = 0;
	while (env)
	{
		len++;
		env = env->next;
	}
	return (len);
}

/*
 * @brief Copy the behavior of export with no args, adding 'declare -x'
 * in front of env variables after sorted them alphabetically.
 * man export says: "When no arguments are given, the results are unspecified"
*/
int	_export_no_args(t_env *env)
{
	char	**var;
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	var = malloc(sizeof(char *) * (_env_len(env) + 1));
	if (var == NULL)
		return (EXIT_FAILURE);
	while (tmp)
	{
		var[i] = ft_strdup(tmp->var);
		i++;
		tmp = tmp->next;
	}
	var[i] = NULL;
	_sort(env, var, _env_len(env));
	ft_str_arr_free(var);
	return (EXIT_SUCCESS);
}
