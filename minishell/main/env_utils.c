/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:17:40 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 18:43:56 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

/*
 * @brief Search for the selected env variable and delete/free it.
*/
void	ms_free_one_env(t_env *env, char *var)
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
	set_env(env);
}
