/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_06.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:39:48 by stelie            #+#    #+#             */
/*   Updated: 2022/04/19 22:35:15 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_pf_putptr(uintptr_t nb, t_bool first)
{
	if (first)
		ft_putstr_fd("0x", 1);
	if (nb < 16)
		ft_putchar_fd(HEXA_LOW[nb], 1);
	else
	{
		ft_pf_putptr(nb / 16, FALSE);
		ft_pf_putptr(nb % 16, FALSE);
	}
}

static int	pf_ptr_null(t_fid *fid)
{
	int	i;

	i = 0;
	if (fid->flag[MINUS])
		write(1, "0x0", 3);
	while (fid->flag[M_WIDTH] > 3 + i++)
		write(1, " ", 1);
	if (fid->flag[MINUS] == 0)
		write(1, "0x0", 3);
	return (ft_max(3, fid->flag[M_WIDTH]));
}

int	pf_ptr(uintptr_t addr, t_fid *fid)
{
	size_t	len;
	int		i;

	if (addr == 0)
		return (pf_ptr_null(fid));
	i = 0;
	len = 2 + ft_hexalen(addr);
	if (fid->flag[MINUS])
		ft_pf_putptr(addr, TRUE);
	while ((size_t)fid->flag[M_WIDTH] > len + i++)
		write(1, " ", 1);
	if (fid->flag[MINUS] == 0)
		ft_pf_putptr(addr, TRUE);
	return (ft_max(len, fid->flag[M_WIDTH]));
}
