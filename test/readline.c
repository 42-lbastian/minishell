#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <signal.h>

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *str1, char *str2)
{
	char	*res;
	int		i;

	if (ft_strlen(str1) == 0)
		return (str2);
	if (ft_strlen(str2) == 0)
		return (str1);
	res = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	i = 0;
	while (str2[i])
	{
		res[i + ft_strlen(str1)] = str2[i];
		i++;
	}
	res[i + ft_strlen(str1)] = '\0';
	return (res);
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
	printf("\n");
}

int main(int argc, char **argv)
{	
	char *str;
	
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &ft_quit);
//	signal(SIGTERM, SIG_IGN);
//	signal(SIGKILL, SIG_IGN);
//	signal(SIGABRT, SIG_IGN);

	while (1)
	{
		str = readline("");
		if (ft_strcmp(str, "exit") == 0)
			break;
		printf("|%s|", str);
		if (ft_strlen(str) != 0)
			add_history(str);
		printf("\n");
	}
	return (0);
}
