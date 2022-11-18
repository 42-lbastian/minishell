#include "../include/minishell.h"

int	ft_special_char(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	ft_belong_good_special(char c, t_struct *main)
{
	int	i;

	i = 0;
	while (i < NB_CHAR_VALID)
	{
		if (c == main->char_check.char_valid[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_exclude_special(char c, t_struct *main)
{
	if (ft_is_alpha(c) || ft_belong_good_special(c, main))
		return (1);
	return (0);
}
