#include "../include/minishell.h"

int	ft_strcmp_2(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	if (!str1)
		return (1);
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

char	*ft_strcpy_2(char *str)
{
	char	*ret;
	int		i;

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
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strjoin_2(char *dest, char *str, int start)
{
	int	i;
	int	j;

	j = start;
	i = 0;
	//printf("start %d\n", start);
	if (str)
	{
		while (str[i])
		{
			dest[j] = str[i];
			i++;
			j++;
		}
	}
	else
		dest = NULL;
	return (j);
}
