/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:32:02 by stelie            #+#    #+#             */
/*   Updated: 2022/11/27 19:03:37 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_ITOA
*/

static unsigned int	_def_full_len(long nb)
{
	unsigned int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*_nb_zero(char *res)
{
	res[0] = '0';
	return (res);
}

/*
 * @brief Transform a given int n into a string.
 * @return returns the string created from the given int n.
*/
char	*ft_itoa(int n)
{
	unsigned int	fulllen;
	long			nb;
	char			*res;

	nb = n;
	fulllen = _def_full_len(nb);
	res = malloc(sizeof(char) * (fulllen + 1));
	if (res == NULL)
		return (NULL);
	res[fulllen--] = '\0';
	if (nb == 0)
		return (_nb_zero(res));
	if (nb < 0)
	{
		nb = -nb;
		res[0] = '-';
	}
	while (nb > 0)
	{
		res[fulllen--] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (res);
}
