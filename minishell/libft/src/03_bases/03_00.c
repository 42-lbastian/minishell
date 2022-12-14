/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:00:38 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 11:29:12 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Take a binary number into a string form and
 * transforms it into a decimal number.
 * @return returns an int, the decimal value of bin.
*/
int	ft_bin_to_int_dec(char *bin)
{
	int		nbr;
	int		mult;
	size_t	len;

	nbr = 0;
	mult = 0;
	len = ft_strlen(bin);
	while (len > 0)
	{
		len--;
		nbr = nbr + ((bin[len] - '0') * (ft_power(mult, 2)));
		mult++;
	}
	return (nbr);
}

/*
 * @brief Take an octal number into a string form and
 * transforms it into a decimal number.
 * @return returns an int, the decimal value of oct.
*/
int	ft_oct_to_int_dec(char *oct)
{
	int		nbr;
	int		mult;
	size_t	len;

	nbr = 0;
	mult = 0;
	len = ft_strlen(oct);
	while (len > 0)
	{
		len--;
		nbr = nbr + ((oct[len] - '0') * (ft_power(mult, 8)));
		mult++;
	}
	return (nbr);
}

static int	_get_hex_val(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	return (ft_ctoupper(c) - 55);
}

/*
 * @brief Take an hexadecimal number into a string form and
 * transforms it into a decimal number.
 * @return returns an int, the decimal value of hex.
*/
int	ft_hex_to_int_dec(char *hex)
{
	int		nbr;
	int		mult;
	size_t	len;

	nbr = 0;
	mult = 0;
	len = ft_strlen(hex);
	while (len > 0)
	{
		len--;
		nbr = nbr + (_get_hex_val(hex[len]) * ft_power(mult, 16));
		mult++;
	}
	return (nbr);
}
