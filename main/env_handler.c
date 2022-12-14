/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:30:37 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 18:04:30 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		ft_free(env->value);
		ft_free(env->var);
		ft_free(env);
		env = temp;
	}
}
