/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:23 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/16 20:08:24 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_lst_new_env(char *var, char *value)
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

t_env	*ft_lst_last_env(t_env *st)
{
	while (st && st->next)
		st = st->next;
	return (st);
}

int	ft_lst_add_back_env(t_env **st, t_env *new)
{
	if (!new)
		return (1);
	if (st && (*st))
		ft_lst_last_env((*st))->next = new;
	else
		(*st) = new;
	return (0);
}
