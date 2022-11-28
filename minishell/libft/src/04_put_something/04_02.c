/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:01:44 by krozis            #+#    #+#             */
/*   Updated: 2022/11/27 19:23:05 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbr_fd(long long nbr, int fd)
{
	if (nbr == LLONG_MIN)
	{
		ft_putchar_fd('-', fd);
		ft_putlnbr_fd(922337203685477580, fd);
		nbr = 8;
	}
	else if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putlnbr_fd(nbr / 10, fd);
		ft_putlnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd('0' + nbr, fd);
}
