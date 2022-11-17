#include "../include/minishell.h"

char	*ft_remove_quotes(char *str)
{
	char	*temp;
	int		i;
	int		j;
	int		quotes;

	i = 0;
	j = 0;
	quotes = 0;
	temp = malloc(sizeof(char) * (ft_count_remove_quotes(str) + 1));
	if (!temp)
		return (NULL);
	temp[ft_count_remove_quotes(str)] = '\0';
	while (str[i])
	{
		if (str[i] == '"' && quotes == 0)
			quotes = 1;
		else if (str[i] == '\'' && quotes == 0)
			quotes = 2;
		else if ((str[i] == '\'' && quotes == 2)
			|| (str[i] == '"' && quotes == 1))
			quotes = 0;
		else
		{
			temp[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);
	return (temp);
}

int	ft_main_remove_quotes(t_list **lst)
{
	t_list *temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		(*lst)->content = ft_remove_quotes((*lst)->content);
		if (!(*lst)->content)
			return (1);
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
