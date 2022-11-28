/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:02:05 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/28 13:32:01 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_free_strcpy_cmd(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free (ret[i]);
		i++;
	}
	free (ret);
}

char	**ms_strcpy_cmd(char **arr)
{
	char	**ret;
	int		i;

	i = 0;
	while (arr[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	ret[i] = NULL;
	i = 0;
	while (arr[i])
	{
		ret[i] = ms_strcpy_2(arr[i]);
		if (!ret[i])
		{
			ms_free_strcpy_cmd(ret);
			return (NULL);
		}
		i++;
	}
	return (ret);
}
