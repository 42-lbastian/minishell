/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:23 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/22 17:10:26 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

t_env	*ms_lst_last_env(t_env *st)
{
	while (st && st->next)
		st = st->next;
	return (st);
}

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
