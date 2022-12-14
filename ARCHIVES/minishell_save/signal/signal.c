#include "../include/minishell.h"

void	child_signal(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		g_glob.ret = 130;
		g_glob.sigint = 1;
	}
}

void	parent_signal(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_glob.ret = 130;
	}
}

void	get_signal(int sig)
{
	if (g_glob.pid)
		child_signal(sig);
	else
		parent_signal(sig);
}

void	signals_handler(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, get_signal);
}
