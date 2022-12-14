/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:25:53 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 10:04:56 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief Liberates one t_env item.
*/
static void	_free_one_env_item(t_env *env)
{
	ft_free(env->var);
	ft_free(env->value);
	env->next = NULL;
	ft_free(env);
}

/*
 * @brief Search for the selected env variable and delete/free it.
 * @return Returns a pointer to the 1st element of env;
*/
static t_env	*_unset_one_env(t_env *env, char *var)
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
				_free_one_env_item(temp);
			}
			else
			{
				prev->next = temp->next;
				_free_one_env_item(temp);
			}
			break ;
		}
		prev = temp;
		temp = temp->next;
	}
	return (env);
}

/*
 * @brief Unset builtin mandatory in the project.
*/
int	unset_builtin(char **args)
{
	int		i;
	t_env	*env;

	i = 0;
	env = get_env();
	while (args[i])
	{
		env = _unset_one_env(env, args[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
