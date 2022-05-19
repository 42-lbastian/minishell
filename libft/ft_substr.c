/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:59:17 by hspriet           #+#    #+#             */
/*   Updated: 2021/12/13 10:58:02 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	resize(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s) <= (int)start)
	{
		return (0);
	}
	while (i < len && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!s)
		return (NULL);
	len = resize(s, start, len);
	s2 = (char *) malloc(sizeof(char) * len + 1);
	i = 0;
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[i + start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
