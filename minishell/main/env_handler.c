/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:30:37 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 15:23:11 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*_get_env(t_env *env)
{
	static t_env	*static_env = NULL;

	if (env != NULL)
		static_env = env;
	return (static_env);
}

/*
 * @brief Allows to update the existing t_env.
*/
void	set_env(t_env *env)
{
	_get_env(env);
}

/*
 * @brief Returns the actual t_env existing.
 */
t_env	*get_env(void)
{
	return (_get_env(NULL));
}

/*
 * @brief Frees and NULLifies the given t_env.
*/
void	free_env(t_env *env)
{
	t_env	*temp;

	while (env)
	{
		temp = (env)->next;
		free(env->value);
		free(env->var);
		free(env);
		env = NULL;
		env = temp;
	}
}

/*
 * @brief Get the value of the given env variable.
 * @return Returns a pointer to the newly created string.
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
