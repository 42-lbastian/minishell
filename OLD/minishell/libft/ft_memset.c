/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:57:45 by hspriet           #+#    #+#             */
/*   Updated: 2021/11/23 15:56:02 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset( void *b, int c, size_t len )
{
	char		*tmp;
	size_t		i;

	tmp = b;
	i = 0;
	while (len > i)
	{
		tmp[i++] = (unsigned char)c;
	}
	return (b);
}
