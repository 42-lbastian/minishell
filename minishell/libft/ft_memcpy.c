/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:52:12 by hspriet           #+#    #+#             */
/*   Updated: 2021/12/13 10:47:51 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy( void *destination, const void *source, size_t size)
{
	size_t					i;
	unsigned char			*tmp;
	unsigned const char		*tmp2;

	if (destination == NULL && source == NULL)
		return (NULL);
	tmp = (unsigned char *)destination;
	tmp2 = (unsigned char *)source;
	i = 0;
	while (size != i)
	{
		*((char *)tmp + i) = *((char *)tmp2 + i);
		i++;
	}
	return (tmp);
}
