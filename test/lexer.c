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
	return (res);
}

char *ft_check_quotes(char *str)
{
	int double_quotes;
	int simple_quotes;
	int i;
	int last_double_q;
	int last_simple_q;
	char *res;

	double_quotes = 0;
	simple_quotes = 0;
	last_double_q = 0;
	last_simple_q =0;
	i = 0;
	res = NULL;
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
	if (simple_quotes == 1 && double_quotes == 1)
	{
		res = ft_remove_char(str, last_simple_q);
		res = ft_remove_char(res, last_double_q);
	}
	else if (simple_quotes == 1)
	{
		res = ft_remove_char(str, last_simple_q);
	}
	else if (double_quotes == 1)
		res = ft_remove_char(str, last_double_q);
	return (res);
}

int main(int argc, char **argv)
{
	printf ("Arg: |%s|\n", argv[1]);
	printf ("Clear |%s|", ft_check_quotes(argv[1]));
	return (0);
}
