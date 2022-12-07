/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:14:47 by stelie            #+#    #+#             */
/*   Updated: 2022/12/07 17:54:53 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**_get_wd(char **wd)
{
	static char	**static_wd = NULL;

	if (wd != NULL)
		static_wd = wd;
	return (static_wd);
}

void	set_wd(char **wd)
{
	_get_wd(wd);
}

char	**get_wd(void)
{
	return (_get_wd(NULL));
}

int	ms_init_wd(void)
{
	char	*buf;
	char	**wd;

	wd = NULL;
	wd = malloc(sizeof(char *) * 3);
	if (wd == NULL)
		return (EXIT_FAILURE);
	buf = NULL;
	buf = getcwd(buf, 0);
	wd[PWD] = ft_strdup(buf);
	if (wd[PWD] == NULL)
	{
		ft_free(wd);
		return (EXIT_FAILURE);
	}
	wd[OLDPWD] = ft_strdup(buf);
	if (wd[OLDPWD] == NULL)
	{
		ft_free(wd[PWD]);
		ft_free(wd);
		return (EXIT_FAILURE);
	}
	free(buf);
	set_wd(wd);
	return (EXIT_SUCCESS);
}

void	free_wd(char **wd)
{
	ft_free(wd[PWD]);
	ft_free(wd[OLDPWD]);
	ft_free(wd);
}
