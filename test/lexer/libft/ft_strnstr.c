/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:18:14 by hspriet           #+#    #+#             */
/*   Updated: 2021/12/09 15:38:18 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2[i])
	{
		return ((char *) s1);
	}
	while (i < len && s1[i])
	{
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && (s2[j] && len > i + j))
			{
				j++;
			}
			if ((int)j == ft_strlen(s2))
				return ((char *) &s1[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
