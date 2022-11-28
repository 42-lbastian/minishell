/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:07:03 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 17:15:27 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	_cd_home(t_env *env)
{
	char	*home_path;
	int		err_code;

	err_code = 0;
	home_path = get_env_value(env, "HOME");
	if (ft_strlen(home_path) == 0)
		err_code = ft_putmsg_fd(ERR_HOME_NOT_SET, STDERR_FILENO, EXIT_FAILURE);
	else
		err_code = chdir(home_path);
	ft_free(home_path);
	return (EXIT_SUCCESS);
}

int	cd_builtin(char	**args)
{
	t_env	*env;

	env = get_env();
	if (args == NULL || env == NULL)
		return (EXIT_FAILURE);
	if (args[1] == NULL)
		return (_cd_home(env));
	return (EXIT_SUCCESS);
}
