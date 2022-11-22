/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:16 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/22 17:10:46 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	_display_env(t_env *env)
{
	while (env->var && env->value)
	{
		printf("\n\nvar = %s\nvalue = %s\n", env->var, env->value);
		if (env->next == NULL)
			break ;
		env = env->next;
	}
}

static int	ms_str_trim_env(char *str, t_env **st)
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

void	ms_clear_env(t_env **st)
{
	t_env	*temp;

	while ((*st))
	{
		temp = (*st)->next;
		free((*st)->value);
		free((*st)->var);
		free((*st));
		(*st) = NULL;
		(*st) = temp;
	}
}

int	ms_create_env(char **envp, t_env **st)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ms_str_trim_env(envp[i], st) == EXIT_FAILURE)
		{
			ms_clear_env(st);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
