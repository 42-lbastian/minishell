#include "../include/minishell.h"

int	ft_size_env_var(t_env *st, char *str, int index, int fact)
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

int	ft_split_expand(t_list **lst, char **split)
{
	int i;

	i = 1;
	if (!split)
		return (1);
	(*lst)->content = ft_strjoin_2(((*lst)->content), split[0]);
	free(split[0]);
	while (split[i])
	{
		if (ft_lstadd(lst, ft_lst_new_join(split[i], CMD)))
			return (1);
		(*lst) = (*lst)->next;
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

int	ft_error_return(char *str)
{
	free(str);
	return (1);
}

int	ft_replace(t_list **lst, t_env *st)
{
	char	*temp;
	char	*str;
	int		i;
	int		j;
	int		quotes;

	i = 0;
	quotes = 0;
	str = ft_strcpy_2((*lst)->content);
	if (!str)
		return (1);
	free((*lst)->content);
	(*lst)->content = NULL;
	temp = NULL;
	while (str[i])
	{
		if (str[i] == '\'' && quotes == 0)
			quotes = 1;
		else if (str[i] == '"' && quotes == 0)
			quotes = 2;
		else if ((str[i] == '\'' && quotes == 1) || (str[i] == '"' && quotes == 2))
			quotes = 0;
		if (str[i] == '$' && quotes != 1)
		{
			i++;
			if (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != '$'
				&& str[i] != ' ')
			{
				j = i;
				while (str[i] && str[i] != '\'' && str[i] != '"'
					&& str[i] != '$' && str[i] != ' ')
					i++;
				temp = ft_find_var((ft_substr(str, j, i - j)), st);
				if (!temp)
					return (ft_error_return(str));
				if (quotes == 2 || ft_strlen(temp) == 0)
					(*lst)->content = ft_strjoin_2((*lst)->content, temp);
				else
					if (ft_split_expand(lst, ft_split(temp, ' ')))
						return (ft_error_return(str));
			}
			else
				(*lst)->content = ft_strjoin_c((*lst)->content, '$');
		}
		else
		{
			(*lst)->content = ft_strjoin_c((*lst)->content, str[i]);
			i++;
		}
		if (!(*lst)->content)
			return (ft_error_return(str));
	}
	free(str);
	return (0);
}

int	ft_main_replace_env(t_list **lst, t_env *st)
{
	t_list	*temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		if ((*lst)->type != LIMITOR)
			if (ft_replace(lst, st) || !(*lst)->content)
				return (1);
		//(*lst)->content = ft_remove_quotes((*lst)->content);
		//if (!(*lst)->content)
		//	return (1);
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
