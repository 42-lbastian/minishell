/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:14:12 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 10:54:04 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief handle the CTRL+C signal for the main process
 * @param sig: the signal (here SIGINT)
 * @todo set the error code (130 for CTRL+C)
 */
static void	_signal(int sig)
{
	if (sig == SIGINT)
	{
		set_err_code(ERR_CODE_CTRL_D);
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/*
 *@brief signal handler for main process
 *@param ARGS: just here to avoid "not used variable" error
*/
void	signal_handler(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, _signal);
}
