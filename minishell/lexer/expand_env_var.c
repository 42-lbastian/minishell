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
	//printf("start %d\tlenght %d\n", start, lenght);
	//printf("Temp size |%s|\n", temp);
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
	//printf("Size env var %d\n", size);
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

char	*ft_replace(int size, t_List st, char *str)
{
	char	*temp;
	int		i;
	int		y;
	int		j;

	i = 0;
	y = 0;
	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (NULL);
	//printf("Size %d\n", size);
	temp[size] = '\0';
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != '$'
				&& str[i] != ' ')
			{
				j = i;
				while (str[i] && str[i] != '\'' && str[i] != '"'
					&& str[i] != '$' && str[i] != ' ')
					i++;
				y = ft_strjoin_2(temp, ft_find_var((ft_substr(str, j, i - j)),
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
			//printf("y %d\t%d\t|%c|\n", y, i, str[i]);
			temp[y] = str[i];
			i++;
			y++;
		}
	}
	//printf("Size Final %d\n", ft_strlen(temp));
	free(str);
	return (temp);
}

char	*ft_main_replace_env(char *str, t_List st)
{
	int	index;
	int	size;

	index = 0;
	size = ft_count_char(str);
	//printf("Count char %d\n", size);
	size += ft_count_nb_quotes(str);
	//printf("Count quotes %d\n", size);
	while (str[index])
	{
		size += ft_size_env_var(st, str, index, 0);
		index = ft_size_env_var(st, str, index, 1);
	}
	str = ft_replace(size, st, str);
	if (!str)
		return (NULL);
	return (str);
}
