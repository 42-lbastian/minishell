/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:46:53 by stelie            #+#    #+#             */
/*   Updated: 2022/04/19 22:29:00 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_size(char const *s, char c)
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

static size_t	get_word_nbr(char const *s, char c)
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

static char	*get_wd(const char *s, char c)
{
	int		size;
	int		j;
	char	*str;

	j = 0;
	size = get_word_size(s, c);
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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (get_word_nbr(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			tab[i] = get_wd(s, c);
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
