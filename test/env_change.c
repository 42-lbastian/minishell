#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void	ft_print_envp(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	printf("\n");
}

void	ft_change_env(char **envp)
{
	envp[0][0] = '|';
	exit (1);
}

int main(int argc, char **argv, char **envp)
{
	int pid;

	ft_print_envp(envp);
	pid = fork();
	if (pid == 0)
		ft_change_env(envp);
	waitpid(pid, NULL, 0);
	ft_print_envp(envp);
	return (0);
}
