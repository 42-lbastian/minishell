/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:46:53 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 10:16:02 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_SPLIT 
*/

static size_t	_get_word_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

static size_t	_get_word_nbr(char const *s, char c)
{
	size_t	wd_nbr;

	wd_nbr = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			wd_nbr++;
			while (*s && *s != c)
				s++;
		}
		if (*s == c)
			while (*s && *s == c)
				s++;
	}
	return (wd_nbr);
}

static char	*_get_word(const char *s, char c)
{
	int		size;
	int		j;
	char	*str;

	j = 0;
	size = _get_word_size(s, c);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (j < size)
	{
		str[j] = *s;
		s++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

/*
 * @brief Splits the given string into differents strings,
 * with a given delimiter
 * @param s: the string to split
 * @param c: the delimiter
 * @return Returns a char** containing all the substrings from splitting
*/
char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (_get_word_nbr(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			tab[i] = _get_word(s, c);
			if (tab[i] == NULL)
				return (NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
