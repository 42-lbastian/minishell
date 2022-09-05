#include "../include/minishell.h"

int	ft_size_env_var(t_List st, char *str, int index, int fact)
{
	int		lenght;
	int		start;
	char	*temp;
	int		size;

	size = 0;
	start = ft_start_read_var(str, index);
	lenght = ft_lenght_read_var(str, index);
	if (lenght == 0 && fact == 1)
		return (index + 1);
	if (fact == 1)
		return (start + lenght);
	temp = ft_substr(str, start + 1, lenght);
	while (st)
	{
		if (ft_strcmp_2(st->var, temp) == 0)
		{
			size = ft_strlen(st->value);
			break ;
		}
		st = st->next;
	}
	free(temp);
	return (size);
}

char	*ft_find_var(char *str, t_List st)
{
	if (!str)
		return (NULL);
	while (st)
	{
		if (ft_strcmp_2(st->var, str) == 0)
		{
			free(str);
			return (st->value);
		}
		st = st->next;
	}
	free(str);
	return ("");
}

char	*ft_replace(int size, t_List st, t_list **lst)
{
	char	*temp;
	int		i;
	int		y;
	int		j;
	int		quotes;

	i = 0;
	y = 0;
	quotes = 0;
	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (NULL);
	temp[size] = '\0';
	while ((*lst)->content[i])
	{
		if ((*lst)->content[i] == '\'' && quotes == 0)
			quotes = 1;
		else if ((*lst)->content[i] == '"' && quotes == 0)
			quotes = 2;
		else if (((*lst)->content[i] == '\'' && quotes == 1) || ((*lst)->content[i] == '"' && quotes == 2))
			quotes = 0;
		if ((*lst)->content[i] == '$' && quotes != 1)
		{
			i++;
			if ((*lst)->content[i] && (*lst)->content[i] != '\'' && (*lst)->content[i] != '"' && (*lst)->content[i] != '$'
				&& (*lst)->content[i] != ' ')
			{
				j = i;
				while ((*lst)->content[i] && (*lst)->content[i] != '\'' && (*lst)->content[i] != '"'
					&& (*lst)->content[i] != '$' && (*lst)->content[i] != ' ')
					i++;
				y = ft_strjoin_2(temp, ft_find_var((ft_substr((*lst)->content, j, i - j)),
							st), y);
			}
			else
			{
				temp[y] = '$';
				y++;
			}
		}
		else
		{
			temp[y] = (*lst)->content[i];
			i++;
			y++;
		}
	}
	//printf("Str |%s|\tTemp |%s|\n", (*lst)->content, temp);
	//free((*lst)->content);
	return (temp);
}

void	ft_replace_env(t_list **lst, t_List st)
{
	int	index;
	int	size;

	index = 0;
	size = ft_count_char((*lst)->content);
	size += ft_count_nb_quotes((*lst)->content);
	while ((*lst)->content[index])
	{
		size += ft_size_env_var(st, (*lst)->content, index, 0);
		index = ft_size_env_var(st, (*lst)->content, index, 1);
	}
	ft_replace(size, st, lst);
}

int	ft_main_replace_env(t_list **lst, t_List st)
{
	t_list	*temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		if ((*lst)->type != LIMITOR)
		{
			ft_replace_env(lst, st);
			if (!(*lst)->content)
				return (1);
		}
		//(*lst)->content = ft_remove_quotes((*lst)->content);
		//if (!(*lst)->content)
		//	return (1);
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
