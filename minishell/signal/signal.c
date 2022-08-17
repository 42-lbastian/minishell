#include "../include/minishell.h"


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
		glob.ret = 130;
	}
}

void	child_signal(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit: (core dumped)\n", 2);
		glob.ret = 131;
		glob.sigquit = 1;
	}
	else if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		glob.ret = 130;
		glob.sigint = 1;
	}
}

void	get_signal(int sig)
{
	if (glob.pid)
		child_signal(sig);
	else
		parent_signal(sig);
}