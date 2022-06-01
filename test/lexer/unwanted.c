#include "test.h"

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

int	ft_count_quotes(int i, int quotes, t_struct *main, int fact)
{
	if (fact == SIMPLE)
		main->last_simple_q = i;
	else if (fact == DOUBLE)
		main->last_double_q = i;
	if (quotes == 0)
		quotes++;
	else if (quotes == 1)
		quotes--;
	return (quotes);
}

char *ft_check_unwanted(char *str, t_struct *main)
{
	int i;
	int	simple_quotes;
	int	double_quotes;

	double_quotes = 0;
	simple_quotes = 0;
	main->last_double_q = 0;
	main->last_simple_q =0;
	i = 0;
	str = ft_strcpy(str);
	while (str[i])
	{
//		if (ft_exclude_special(str[i], main) == 0)
//			str = ft_remove_char(str, i);
		if (str[i] == '"')
			double_quotes = ft_count_quotes(i, double_quotes, main, DOUBLE);
		if (str[i] == '\'')
			simple_quotes = ft_count_quotes(i, simple_quotes, main, SIMPLE);
//		if (ft_exclude_special(str[i], main) == 1 && str[i])
			i++;
	}
	if (simple_quotes == 1)
	{
		str = ft_remove_char(str, main->last_simple_q);
		if (main->last_double_q > main->last_simple_q)
			main->last_double_q--;
	}
	if (double_quotes == 1)
		str = ft_remove_char(str, main->last_double_q);
	return (str);
}

