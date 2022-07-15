#include "../include/minishell.h"

int		ft_count_nb_quotes(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_interpret_env(char *str, t_List st)
{
	(void)st;
	printf("STR %s\n", str + 2);
	return (str);
}

int		ft_lenght_read_var(char *str, int index)
{
	int	i;
	int	size;

	i = index;
	size = 0;
	while (str[i])
	{
		while (str[i] == '"' || str[i] == '\'')
			i++;
		if (str[i] && str[i] == '$')
		{
			size++;
			i++;
			while (str[i] && str[i] != '"' && str[i] != '\'' && str[i] != '$')
			{
				size++;
				i++;
			}
			return (size - 1);
		}
		else
			i++;
	}
	return (size);
}

int 	ft_start_read_var(char *str, int index)
{
	int i;

	i = index;
	while (str[i] && str[i] != '$')
		i++;
	return (i);
}

int		ft_size_env_var(t_List st, char *str, int index, int fact)
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
			//printf("\nTEST |%s|=|%s|\t%s\n\n", temp, st->var, st->value);
			size = ft_strlen(st->value);
			break;
		}
		//printf("TEST |%s|=|%s|\n", temp, st->var);
		st = st->next;
	}
	free(temp);
	return (size);
}

int		ft_count_char(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != '$')
				while (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != '$')
					i++;
			else
				size++;
		}
		else if (str[i] == '\'' || str[i] == '"')
			i++;
		else
		{
			i++;
			size++;
		}
	}
	return (size);
}

//STRJOIN

void	ft_str_join2(char *dest, char *str, int start)
{
	int	i;
	int	j;

	j = start;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			dest[j] = str[i];
			i++;
			j++;
		}
		//free(str); WTF REPLACE ENV VAR
	}
	else
		dest = NULL;
}

char	*ft_find_var(char *str, t_List st)
{
	if (!str)
		return (NULL);
	while (st)
	{
		if (ft_strcmp_2(st->var, str) == 0)
			return (st->value);
		st = st->next;
	}
	return ("");
}

char	*ft_replace(int size, t_List st, char *str)
{
	char	*temp;
	int		i;
	int		y;
	int		j;

//	(void)st;
	i = 0;
	y = 0;
	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (NULL);
	temp[size] = '\0';
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != '$')
			{
				j = i;
				while (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != '$')
					i++;
				//printf("Substr %s\n", ft_substr(str, j, i - j));
				//printf("Find %s\n", ft_find_var(ft_substr(str, j, i - j), st));
				ft_str_join2(temp, ft_find_var((ft_substr(str, j, i - j)), st), y);
				

				//i -= 2
				
				i--;
				y = i;
			}
			else
			{
				temp[y] = '$';
				y++;
			}
		}
		else
		{
			printf("SIZE %d\tY %d\tI %d\n", size, y, i);
			//printf("CHAR2MERDE %c\n", str[i]);
			temp[y] = str[i];
			i++;
			y++;
		}
	}
	printf("\nSTR %s\n", str);
	printf("TEMP |%s|\n\n", temp);
	free(str);
	return (temp);
}

void	ft_main_replace_env(char *str, t_List st)
{
	int index;
	int	size;

	index = 0;
	size = ft_count_char(str);
	size += ft_count_nb_quotes(str);
	while (str[index])
	{
		size += ft_size_env_var(st, str, index, 0);
		index = ft_size_env_var(st, str, index, 1);
	}
	//printf("SIZE %d\n", size);
	str = ft_replace(size, st, str);
//	if (!str)
	//PROTECT MALLOC		
}

int		ft_env_var(t_list **lst, t_List st)
{
	t_list *temp;

	(void)st;

	temp = (*lst);
	while (lst && (*lst))
	{
		if ((*lst)->type == ARG)
		{
			if ((*lst)->content[0] != '\'')
				ft_main_replace_env((*lst)->content, st);
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
