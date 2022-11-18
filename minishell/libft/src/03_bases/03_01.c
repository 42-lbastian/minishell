/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:23:22 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 11:31:25 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_get_value(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

/*
 * @brief Take a number into a string form and convert it into 
 * a number in the given base.
 * @param base: the base of the given number
 * @param bnbr: the number to convert
 * @return returns an int, converted value of bnbr in the given base.
*/
int	ft_base_to_int_dec(char *base, char *bnbr)
{
	int		nbr;
	int		mult;
	size_t	i;
	size_t	baselen;

	nbr = 0;
	mult = 0;
	i = ft_strlen(bnbr);
	baselen = ft_strlen(base);
	while (i > 0)
	{
		i--;
		nbr = nbr + (_get_value(base, bnbr[i]) * (ft_power(mult, baselen)));
		mult++;
	}
	return (nbr);
}
