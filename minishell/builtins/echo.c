#include "../include/minishell.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
		if (i == 2)
			return (s1[i-1] - s2[i-1]);
		
	}
	return (s1[i] - s2[i]);
}

int is_n(char *str)
{
	
	
	int i;

	i = 0;
	if (str[0] != '-')
	{
		return (0);
	}
	else
	{
		i++;
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;	
		}
	}
	return (1);	
}

int echo(char **str)
{
	int i;
	int n;

	i = 0;
	n = 1;
	i = 1;
	if (str[i])
	{
		while (is_n(str[i]))
		{
			n = 0;
			i++;
		}
		while (str[i])
		{	
			ft_putstr_fd(str[i],1);
			i++;
			if (str[i])
				ft_putstr_fd(" ", 1);
		}
	}
	if (n == 1)
		ft_putstr_fd("\n", 1);
    return (0);
}
