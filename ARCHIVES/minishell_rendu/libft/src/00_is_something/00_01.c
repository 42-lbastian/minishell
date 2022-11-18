/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:20:59 by stelie            #+#    #+#             */
/*   Updated: 2022/04/19 20:48:47 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_ishexa(char *nbr)
{
	while (*nbr)
	{
		if (ft_incharset(ft_ctoupper(*nbr), HEXA_UP) == FALSE)
			return (FALSE);
		nbr++;
	}
	return (TRUE);
}

t_bool	ft_isoctal(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '7'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (TRUE);
	return (FALSE);
}
