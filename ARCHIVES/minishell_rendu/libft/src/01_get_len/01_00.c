/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:08:51 by stelie            #+#    #+#             */
/*   Updated: 2022/11/15 15:24:41 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hexalen(size_t nb)
{
	size_t	len;

	len = 0;
	if (nb < 16)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

size_t	ft_intlen(int nb)
{
	size_t	len;

	if (nb > -10 && nb < 10)
		return (1);
	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

size_t	ft_nbrlen(long nb)
{
	size_t	len;

	len = 0;
	if (nb < 10 && nb > -10)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

size_t	ft_strlen_libft(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
