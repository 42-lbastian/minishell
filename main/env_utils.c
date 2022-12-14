/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:17:40 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 11:26:22 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief Says if a variable exists in the given env.
 * @return Returns true or false.
*/
bool	ms_env_exists(t_env *env, char *var)
{
	t_env	*tmp;

	if (!env || !var)
		return (false);
	tmp = env;
	while (tmp && tmp->var)
	{
		if (ft_strcmp(var, tmp->var) == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

/*
 * @brief Get the value of the given env variable.
 * @return Returns a pointer to the newly created string, containing the value.
*/
char	*ms_get_env_value(t_env *env, char *var)
{
	char	*value;
	t_env	*tmp;

	value = NULL;
	tmp = env;
	while (tmp && tmp->var)
	{
		if (ft_strcmp(var, tmp->var) == 0)
			value = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	return (value);
}

/*
 * @brief Updates the value of an existing env variable.
 * Creates it if not existing.
 * @param env: the t_env to update
 * @param var: the variable to update
 * @param new_value: the new value to 'var'
 * @return Returns EXIT_SUCCESS or EXIT_FAILURE.
*/
int	ms_env_update(t_env **env, char *var, char *new_value)
{
	t_env	*tmp;

	tmp = (*env);
	if (var == NULL)
		return (EXIT_FAILURE);
	if (env == NULL || ms_env_exists((*env), var) == false)
		return (ms_add_back_env(env, ms_new_env(ft_strdup(var) \
		, ft_strdup(new_value))));
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
			return (EXIT_SUCCESS);
		}
		tmp = tmp->next;
	}
	return (EXIT_FAILURE);
}

/*
 * NOT DOCUMENTED
*/
char	*ms_find_var(char *str, t_env *st)
{
	if (!str)
		return (NULL);
	if (ft_strcmp(str, "?") == 0)
	{
		free(str);
		return (ft_itoa(get_err_code()));
	}
	while (st)
	{
		if (ft_strcmp(st->var, str) == 0)
		{
			free(str);
			return (ft_strdup(st->value));
		}
		st = st->next;
	}
	free(str);
	return (ft_strdup(""));
}
