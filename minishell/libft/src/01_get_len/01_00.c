/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:08:51 by stelie            #+#    #+#             */
/*   Updated: 2022/11/27 20:13:40 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Gives the size in characters of an hexadecimal number.
 * @return returns the size of nb in a size_t format.
*/
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

/*
 * @brief Gives the size in characters of an int number.
 * @return returns the size of nb in a size_t format.
*/
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

/*
 * @brief Gives the size in characters of a long number.
 * @return returns the size of nb in a size_t format.
*/
size_t	ft_nbrlen(long long nb)
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

/*
 * @brief Gives the size in characters of string.
 * @return returns the size of the string s in a size_t format.
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
 * @brief Gives the size of a string array.
 * @return returns the size of the array a size_t format.
*/
size_t	ft_arrlen(char **array)
{
	size_t	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}
