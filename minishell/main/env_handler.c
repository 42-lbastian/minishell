/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:30:37 by stelie            #+#    #+#             */
/*   Updated: 2022/11/23 12:42:18 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
