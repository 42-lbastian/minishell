/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:33:41 by hspriet           #+#    #+#             */
/*   Updated: 2021/12/09 14:36:48 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	i;

	i = 0;
	lendest = ft_strlen(s1);
	lensrc = ft_strlen(s2);
	if (n == 0)
		return (lensrc);
	if (n <= lendest)
		return (n + lensrc);
	while (n && (--n - lendest) && s2[i])
	{
		s1[lendest + i] = s2[i];
		i++;
	}
	s1[lendest + i] = '\0';
	return (lensrc + lendest);
}
