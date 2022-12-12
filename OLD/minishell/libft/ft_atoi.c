/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <hspriet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:52:14 by hspriet           #+#    #+#             */
/*   Updated: 2022/03/03 17:12:21 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isdigit2(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

long	int	ft_atol(const char *str)
{
	int			i;
	long int	nb;
	int			sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] && ((str[i] <= 13 && str[i] >= 9) || str[i] == ' '))
	{
		i++;
	}
	if (str[i] == '+' && ft_isdigit2(str[i + 1]))
		i++;
	if (str[i] == '-' && ft_isdigit2(str[i + 1]))
	{
		sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit2(str[i]))
	{
		nb = str[i] - 48 + nb * 10;
		i++;
	}
	return (nb * sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			nb;
	int			sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] && ((str[i] <= 13 && str[i] >= 9) || str[i] == ' '))
	{
		i++;
	}
	if (str[i] == '+' && ft_isdigit2(str[i + 1]))
		i++;
	if (str[i] == '-' && ft_isdigit2(str[i + 1]))
	{
		sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit2(str[i]))
	{
		nb = str[i] - 48 + nb * 10;
		i++;
	}
	return (nb * sign);
}
