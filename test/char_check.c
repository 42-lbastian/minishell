#include "test.h"

int	ft_belong_cmd_start(char c)
{
	if (c != ' ' && c != '"' && c != '\'' && c != ' ' && c != '<' && c != '>' && c != '|')
		return (1);
	return (0);
}

int	ft_belong_cmd_end(char c)
{
	if (c != ' ' && c != '<' && c != '>' && c != '|')
		return (1);
	return (0);
}

int	ft_special_char(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}


int	ft_exclude_char(char c)
{
	if (ft_special_char(c) == 0 && c != '"' && c != '\'')
		return (1);
	return (0);
}
