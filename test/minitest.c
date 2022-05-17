#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	if (!str1)
		return (0);
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (i < ft_strlen(str1) || i < ft_strlen(str2))
		return (1);
	return (0);
}

void	ft_quit(int i)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	printf("\n");
}

void	ft_signal(int signum, void *handler)
{
	struct sigaction act;
	act.sa_handler = handler;
	sigaction(signum, &act, NULL);
}

int main(int argc, char **argv)
{	
	char *str;

	/*		SIGNAL
	**	ctrl \	SIGQUIT
	**	ctrl c	SIGINT
	**	ctrl d	EOF
	*/

	ft_signal(SIGQUIT, SIG_IGN);
	ft_signal(SIGINT, &ft_quit);

	while (1)
	{
		str = readline("");
		if (ft_strcmp(str, "exit") == 0)
			break;
		printf("|%s|", str);
		if (ft_strlen(str) != 0)
			add_history(str);
		printf("\n");
		free(str);
	}
	rl_clear_history();
	return (0);
}
