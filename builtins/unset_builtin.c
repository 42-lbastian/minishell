/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:25:53 by stelie            #+#    #+#             */
/*   Updated: 2022/12/05 13:48:31 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	unset_builtin(char **args)
{
	int		i;
	t_env	*env;

	i = 0;
	env = get_env();
	while (args[i])
	{
		env = ms_free_one_env(env, args[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
