/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:42:56 by hspriet           #+#    #+#             */
/*   Updated: 2021/12/11 17:03:58 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*tmp;
	char		*tmp2;

	tmp = (char *)dest;
	tmp2 = (char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (tmp > tmp2)
		while (n-- > 0)
			tmp[n] = tmp2[n];
	else
	{
		while (i < n)
		{
			tmp[i] = tmp2[i];
			i++;
		}
	}
	return (dest);
}
