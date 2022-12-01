/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:38:11 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/01 18:39:22 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_exec_cmd(char *path, char **complete_cmd, char **env_arr)
{
	if (!env_arr)
		return (ft_putmsg_fd(ERR_MALLOC_ENV_ARR, STDERR_FILENO, EXIT_FAILURE));
	execve(path, complete_cmd, env_arr);
	return (1);
}
