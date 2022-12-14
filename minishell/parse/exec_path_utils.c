/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:48:52 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/29 16:32:44 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_env_size(t_env *st)
{
	int	i;

	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
}

char	*ms_strjoin_env(char *str1, char *str2, char c, int i)
{
	char	*dst;
	int		y;

	y = 0;
	dst = malloc(sizeof(char) * (ms_strlen(str1) + ms_strlen(str2) + 2));
	if (!dst)
		return (NULL);
	while (str1[i])
	{
		dst[y] = str1[i];
		y++;
		i++;
	}
	dst[y] = c;
	y++;
	i = 0;
	while (str2[i])
	{
		dst[y] = str2[i];
		y++;
		i++;
	}
	dst[y] = 0;
	return (dst);
}
