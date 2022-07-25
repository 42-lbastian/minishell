#include "../include/minishell.h"

int	ft_count_spaces(char *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != ' ')
		{
			i++;
			size++;
		}
		size++;
		while (str[i] && str[i] == ' ')
			i++;
	}
	size--;
	return (size);
}

char	*ft_spaces_flag(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*temp;

	i = 0;
	j = 0;
	size = ft_count_spaces(str);
	temp = malloc(sizeof(char) * (size + 1));
	temp[size] = '\0';
	if (!temp)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] != ' ')
		{
			temp[j] = str[i];
			j++;
			i++;
		}
		if (str[i] && j < size)
		{
			j++;
			temp[i] = ' ';
		}
		while (str[i] && str[i] == ' ')
			i++;
	}
	free(str);
	return (temp);
}

int	ft_remove_spaces(t_list **lst)
{
	t_list	*temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		if ((*lst)->type == FLAG)
			(*lst)->content = ft_spaces_flag((*lst)->content);
		if ((*lst)->type == ARG && ((*lst)->content[0] != '"'
				&& (*lst)->content[0] != '\''))
			(*lst)->content = ft_spaces_flag((*lst)->content);
		if (!(*lst)->content)
			return (1);
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
