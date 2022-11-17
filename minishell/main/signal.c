#include "../include/minishell.h"

/*
 * @brief handle the CTRL+C signal for the main process
 * @param sig: the signal (here SIGINT)
 * @todo set the error code (130)
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
void	global_signals_handler(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, global_signal);
}

/*
 * @brief: old signal handler
 * @author: hspriet
 * 
 *
 void	parent_signal(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("\b\b  \b\b", 2);
	}
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		g_glob.ret = 130;
	}
}

void	child_signal(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit: (core dumped)\n", 2);
		g_glob.ret = 131;
		g_glob.sigquit = 1;
	}
	else if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		g_glob.ret = 130;
		g_glob.sigint = 1;
	}
}

void	get_signal(int sig)
{
	if (g_glob.pid)
		child_signal(sig);
	else
		parent_signal(sig);
}
*/
