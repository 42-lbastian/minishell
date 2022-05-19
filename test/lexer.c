#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_remove_char(char *str, int index)
{
	char *res;
	int i;
	int y;

	i = 0;
	y = 0;
	res = malloc(sizeof(char) * ft_strlen(str));
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (i != index)
		{
			res[y] = str[i];
			y++;
		}
		i++;
	}
	res[y] = '\0';
	free(str);
	return (res);
}

char *ft_strcpy(char *str)
{
	char *ret;
	int i;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char *ft_check_quotes(char *str)
{
	int double_quotes;
	int simple_quotes;
	int i;
	int last_double_q;
	int last_simple_q;

	double_quotes = 0;
	simple_quotes = 0;
	last_double_q = 0;
	last_simple_q =0;
	i = 0;
	str = ft_strcpy(str);
	while (str[i])
	{
		if (str[i] == '"')
		{
			last_double_q = i;
			if (double_quotes == 0)
				double_quotes++;
			else if (double_quotes == 1)
				double_quotes--;
		}
		if (str[i] == '\'')
		{
			last_simple_q = i;
			if (simple_quotes == 0)
				simple_quotes++;
			else if (simple_quotes == 1)
				simple_quotes--;
		}
		i++;
	}
	if (simple_quotes == 1)
	{
		str = ft_remove_char(str, last_simple_q);
		if (last_double_q > last_simple_q)
			last_double_q--;
	}
	if (double_quotes == 1)
		str = ft_remove_char(str, last_double_q);
	return (str);
}

char *ft_strjoin(char *str, char c)
{
	char *ret;
	int i;

	i = 0;
	if (!str)
	{
		ret = malloc(sizeof(char) * 2);
		if (!ret)
			return (NULL);
		ret[0] = c;
		ret[1] = '\0';
		return (ret);
	}
	ret = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = c;
	ret[i + 1] = '\0';
	free(str);
	return (ret);
}

int	ft_avoid_char(char c)
{
	if (c == ' ' || c == '\\' || c == ';')
		return (0);
	return (1);
}

/*
char **ft_add_cell(char **arr)
{
	char **ret;
	int sec;
	int index;
	int size;

	size = 0;
	sec = 0;
	while (arr[size])
		size++;
	ret = malloc(sizeof(char **) * (size + 1)); 
	ret[size] = NULL;
	if (size == 0)
		return (ret);
	while (arr[sec])
	{
		index = 0;
		ret[sec] = malloc(sizeof(char *) * ft_strlen(arr[sec]));
		while (arr[sec][index])
		{
			ret[sec][index] = arr[sec][index];
			index++;
		}
		ret[sec][index] = '\0';
		sec++;
	}
	return (ret);
}
*/

char ***ft_lexer(char *str)
{
	int i;
	int f_index;
	int s_index;
	char ***ret;

	i = 0;
	ret = malloc(sizeof(char **) * 2);
	ret[0] = malloc(sizeof(char*) * 16);
	ret[1] = NULL;
	ret[0][0] = NULL;
	f_index = 0;
	s_index = 0;
	while (str[i])
	{
		if (ft_avoid_char(str[i]))
		{
			printf("index %d\n", f_index);
			while (str[i] != ' ' && str[i])
			{
	//			ret[s_index] = ft_add_cell(ret[s_index]);
				ret[s_index][f_index] = ft_strjoin(ret[s_index][f_index], str[i]);
				i++;
			}
			f_index++;
			ret[s_index][f_index] = NULL;
		}
		if (str[i] == '"')
		{
			while (str[i] != '"')
			{
				if (str[i] != '\\')
				{}
				i++;
			}
		}
		if (str[i] == '\'')
		{
			while (str[i] != '\'')
			{
				if (str[i] != '\\')
				{}
				i++;
			}
		}
		if (str[i] == ' ')
			i++;
	}
	free(str);
	return (ret);
}

void	ft_print_arr(char ***arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[i][j])
		{
			printf("%s\n", arr[i][j]);
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	char *str_ret;
	char ***arr_lexer;

	printf("Arg: |%s|\n", argv[1]);
	str_ret = ft_check_quotes(argv[1]);
	arr_lexer = ft_lexer(str_ret);
	ft_print_arr(arr_lexer);

//	free(str_ret);
	return (0);
}
