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
	

	if (ft_strcmp(str, "-n"))
	{
		if (str[2] != ' ')
			return (1);
	}
	return (0);	
}

int echo(char **str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	i = 1; //pour les tests
	if (str[i])
	{
		if (!is_n(str[1]))
		{
			while (str[i] == 0)
			{
					i++;
					n = 1;
			}
		}
		while (str[i])
		{
			
			ft_putstr_fd(str[i],1);
			i++;
			if (str[i])
				ft_putstr_fd(" ", 1);
		}
	}
	if (n == 0)
		ft_putstr_fd("\n", 1);
    return (0);
}
