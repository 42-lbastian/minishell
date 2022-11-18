#include "../include/minishell.h"


int		is_good(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_exit(char *str)
{
	int sta;

	if (str)
	{
		if (!is_good(str))
		{
			ft_printf("bash: exit: status numeric argument required\n");
			exit(2);
		}
		sta = ft_atoi(str);
		exit(sta);
	}
	exit(0);
}