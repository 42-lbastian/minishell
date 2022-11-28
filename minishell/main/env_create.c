/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:16 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/28 13:32:01 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * @brief Creates a new t_env item.
 * @return Returns a pointer to the newly created t_env item.
*/
t_env	*ms_lst_new_env(char *var, char *value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env || (!var && !value))
		return (NULL);
	if (!var && value)
	{
		free(value);
		return (NULL);
	}
	if (!value && var)
	{
		free (var);
		return (NULL);
	}
	env->var = var;
	env->value = value;
	env->next = NULL;
	return (env);
}

/*
 * @brief Gets and returns the last item of the given t_env list.
*/
static t_env	*ms_lst_last_env(t_env *st)
{
	while (st && st->next)
		st = st->next;
	return (st);
}

/*
 * @brief Adds a new t_env to an existing t_env*.
 * The new t_env is added at the end of the list.
 * @param st: the existing t_env
 * @param new: the t_env item added to st
 * @return Returns EXIT_SUCCESS or EXIT_FAILURE.
*/
int	ms_lst_add_back_env(t_env **st, t_env *new)
{
	if (!new)
		return (EXIT_FAILURE);
	if (st && (*st))
		ms_lst_last_env((*st))->next = new;
	else
		(*st) = new;
	return (EXIT_SUCCESS);
}

/*
 * @brief Sub-function to initialise t_env.
 * @return Returns EXIT_SUCCESS or EXIT_FAILURE.
*/
static int	_ms_str_trim_env(char *str, t_env **st)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	if (ms_lst_add_back_env(st, ms_lst_new_env(ft_substr(str, 0, i),
				ft_substr(str, i + 1, ft_strlen(str) - i))))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
 * @brief Initalises the given t_env and fill it with envp.
 * @return Returns EXIT_SUCCESS or EXIT_FAILURE.
*/
int	ms_create_env(char **envp, t_env **st)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (_ms_str_trim_env(envp[i], st) == EXIT_FAILURE)
		{
			free_env(*st);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
