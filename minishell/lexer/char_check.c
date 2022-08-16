#include "../include/minishell.h"

int	ft_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_belong_cmd_start(char c)
{
	if (c != ' ' && c && c != '<' && c != '>' && c != '|')
		return (1);
	return (0);
}

int	ft_belong_cmd_end(char c)
{
	if (c != ' ' && c != '<' && c != '>' && c != '|')
		return (1);
	return (0);
}
