/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:17:40 by stelie            #+#    #+#             */
/*   Updated: 2022/12/05 18:12:30 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief Says if a variable exists in the given env.
 * @return Returns true or false.
*/
bool	ms_env_var_exists(t_env *env, char *var)
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
 * @brief Liberates one t_env item.
*/
void	_free_one_env(t_env *env)
{
	ft_free(env->var);
	ft_free(env->value);
	env->next = NULL;
	ft_free(env);
}

/*
 * @brief Get the value of the given env variable.
 * @return Returns a pointer to the newly created string, containing the value.
*/
char	*get_env_value(t_env *env, char *var)
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
 * @brief Search for the selected env variable and delete/free it.
 * @return Returns a pointer to the 1st element of env;
*/
t_env	*ms_free_one_env(t_env *env, char *var)
{
	t_env	*temp;
	t_env	*prev;

	temp = env;
	prev = NULL;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->var, var) == 0)
		{
			if (prev == NULL)
			{
				env = env->next;
				_free_one_env(temp);
			}
			else
			{
				prev->next = temp->next;
				_free_one_env(temp);
			}
			break ;
		}
		prev = temp;
		temp = temp->next;
	}
	return (env);
}

/*
 * @brief Updates the value of an existing env variable.
 * Creates it if not existing.
 * @param env: the t_env to update
 * @param var: the variable to update
 * @param new_value: the new value to 'var'
 * @return Returns EXIT_SUCCESS or EXIT_FAILURE.
*/
int	ms_env_update(t_env *env, char *var, char *new_value)
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
