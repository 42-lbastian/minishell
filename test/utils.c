#include "test.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	if (!str1)
		return (0);
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (i < ft_strlen(str1) || i < ft_strlen(str2))
		return (1);
	return (0);
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

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_calloc_second(int count, size_t size, t_struct *main)
{
	int i;

	i = 0;
	main->ret[main->s_index] = malloc(size * count);
	while (i < count)
	{
		main->ret[main->s_index][i] = NULL;
		i++;
	}
}

void	ft_calloc_first(int count, size_t size, t_struct *main)
{
	int i;

	i = 1;
	main->ret = malloc(size * count);
	while (i < count)
	{
		main->ret[i] = NULL;
		i++;
	}
}
