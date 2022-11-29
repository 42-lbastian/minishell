/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lst_parser_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:36:31 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/29 15:38:51 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_close_return(char *msg, int pip[2][2])
{
	close(pip[1][0]);
	close(pip[1][1]);
	return (ft_putmsg_fd(msg, STDERR_FILENO, EXIT_FAILURE));
}
