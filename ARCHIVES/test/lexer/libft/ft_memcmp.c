/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:29:36 by hspriet           #+#    #+#             */
/*   Updated: 2021/12/11 18:35:17 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp( const void *pointer1, const void *pointer2, size_t size)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (pointer1 == pointer2 || size == 0)
		return (0);
	str1 = (const unsigned char *)pointer1;
	str2 = (const unsigned char *)pointer2;
	while (size--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (size)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
