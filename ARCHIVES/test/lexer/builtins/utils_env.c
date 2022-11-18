#include "../include/minishell.h"

int	is_equal(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

static char	*ft_strcpy2(char const *s, int *i, int size)
{
	int		j;
	char	*ret;

	j = 0;
	ret = (char *) malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (j < size)
	{
		ret[j] = s[*i];
		*i = *i + 1;
		j++;
	}
	ret[j] = 0;
	return (ret);
}

static char	**ft_free_equal(char **ret, int k)
{
	while (k >= 0)
	{
		free(ret[k]);
		k--;
	}
	free(ret);
	return (NULL);
}

char	**ft_trim_equal(char const *s, char charset)
{
	char	**ret;
	int		i;	
	int		j;	
	int		k;
	int		r;

	r = 1;
	k = -1;
	i = 0;
	ret = malloc(sizeof(char *) * (2));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		if (s[i] != charset)
		{
			j = i;
			if(r == 0)
				charset = 127;
			while (s[j] != charset && s[j])
				j++;
			ret[++k] = ft_strcpy2(s, &i, j - i);
			if (!ret[k])
				return (ft_free_equal(ret, k));
		}
		else
		{
			i++;
			r = 0;
		}
	}
	return (ret);
}
