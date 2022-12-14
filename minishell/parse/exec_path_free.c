/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:57:51 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/29 16:58:49 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_free_split(char **all_path)
{
	int	i;

	i = 0;
	while (all_path[i])
	{
		free(all_path[i]);
		i++;
	}
	free(all_path);
}

char	**ms_free_env_arr(char **env_arr)
{
	int	i;

	i = 0;
	while (env_arr[i])
	{
		free (env_arr[i]);
		env_arr[i] = NULL;
		i++;
	}
	free (env_arr);
	env_arr = NULL;
	return (NULL);
}
