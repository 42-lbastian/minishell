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
	i = 0;
	while (str[i])
	{}

}

int main(int argc, char **argv)
{
	return (0);
}
