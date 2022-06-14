/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:01:24 by hspriet           #+#    #+#             */
/*   Updated: 2021/12/09 11:18:41 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*dest;

	dest = malloc(elementCount * elementSize);
	if (dest == NULL)
		return (dest);
	ft_bzero(dest, elementSize * elementCount);
	return (dest);
}
