/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <hspriet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:03:45 by hspriet           #+#    #+#             */
/*   Updated: 2022/03/05 19:41:16 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	how_many_word(char const *str, char charset)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_charset(str[i], charset))
		{
			i++;
		}
		else if (!is_charset(str[i], charset))
		{
			k++;
			while (!is_charset(str[i], charset) && str[i])
				i++;
		}
	}
	return (k);
}

static char	*ft_strcpy(char const *s, int *i, int size)
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

static char	**ft_25_lines(int size)
{
	char	**ret;

	ret = (char **) malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = NULL;
	return (ret);
}

static char	**ft_free(char	**ret, int k)
{
	while (k >= 0)
	{
		free(ret[k]);
		k--;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char charset)
{
	char	**ret;
	int		i;	
	int		j;	
	int		k;	

	k = -1;
	i = 0;
	ret = ft_25_lines(how_many_word(s, charset));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		if (s[i] != charset)
		{
			j = i;
			while (s[j] != charset && s[j])
				j++;
			ret[++k] = ft_strcpy(s, &i, j - i);
			if (!ret[k])
				return (ft_free(ret, k));
		}
		else
			i++;
	}
	return (ret);
}
