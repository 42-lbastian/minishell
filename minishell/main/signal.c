#include "../include/minishell.h"

/*
 * @brief handle the CTRL+C signal for the main process
 * @param sig: the signal (here SIGINT)
 * @todo set the error code (130 for CTRL+C)
 */
void	global_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/*
 *@brief signal handler for main process
*/
void	global_signals_handler(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, global_signal);
}
