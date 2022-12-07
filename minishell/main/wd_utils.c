/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:14:47 by stelie            #+#    #+#             */
/*   Updated: 2022/12/07 12:41:00 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * save the values for PWD and OLDPWD (in that ORDER)
*/
static t_env	*_get_wd(t_env *wd)
{
	static t_env	*static_wd = NULL;

	if (wd != NULL)
		static_wd = wd;
	return (static_wd);
}

/*
 * @brief Allows to update the existing wd.
*/
void	set_wd(t_env *wd)
{
	_get_wd(wd);
}

/*
 * @brief Returns the actual wd existing.
 */
t_env	*get_wd(void)
{
	return (_get_wd(NULL));
}

int	ms_init_wd(t_env **wd)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, 0);
	if (buf == NULL)
		return (EXIT_FAILURE);
	*wd = ms_new_env(ft_strdup(buf), ft_strdup(buf));
	ft_free(buf);
	if (wd == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
