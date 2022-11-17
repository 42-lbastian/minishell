/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:16 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/17 12:12:50 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_str_trim_env(char *str, t_env **st)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	if (ft_lst_add_back_env(st, ft_lst_new_env(ft_substr(str, 0, i),
				ft_substr(str, i + 1, ft_strlen(str) - i))))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_clear_env(t_env **st)
{
	t_env	*temp;

	while ((*st))
	{
		temp = (*st)->next;
		free((*st)->value);
		free((*st)->var);
		(*st) = (*st)->next;
		free((*st));
		(*st) = temp;
	}
}

int	ft_create_env(char **envp, t_env **st)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_str_trim_env(envp[i], st))
		{
			ft_clear_env(st);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
