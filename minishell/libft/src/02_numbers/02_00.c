/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:08:02 by stelie            #+#    #+#             */
/*   Updated: 2022/12/13 16:27:48 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_ATOI
 * FT_MAX
 * FT_MIN
 * FT_POWER
*/

/*
 * @brief Transforms a digit constitued string into an int.
 * @return Returns an int
*/
int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && (*str < ':' && *str > '/'))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}

/*
 * @brief Gets the bigger between two given int.
 * @return returns the bigger between ints a and b.
*/
int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

/*
 * @brief Gets the smaller between two given int.
 * @return returns the smaller between ints a and b.
*/
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/*
 * @brief Calculates power number.
 * @param power: the value of the power
 * @param nbr: the number to power.
 * @return returns the result of nbr^power.
*/
int	ft_power(int power, int nbr)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (nbr);
	return (nbr * ft_power(power - 1, nbr));
}

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;

	if (ft_strcmp(str, "9223372036854775808") == 0)
		return (0);
	if (ft_strcmp(str, "-9223372036854775808") == 0)
		return (LLONG_MIN);
	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && (*str < ':' && *str > '/'))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}
