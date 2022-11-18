/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_06.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:39:48 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 13:27:25 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_pf_putptr(uintptr_t nb, bool first)
{
	if (first)
		ft_putstr_fd("0x", 1);
	if (nb < 16)
		ft_putchar_fd(HEXA_LOW[nb], 1);
	else
	{
		_ft_pf_putptr(nb / 16, false);
		_ft_pf_putptr(nb % 16, false);
	}
}

static int	_pf_ptr_null(t_fid *fid)
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
		return (_pf_ptr_null(fid));
	i = 0;
	len = 2 + ft_hexalen(addr);
	if (fid->flag[MINUS])
		_ft_pf_putptr(addr, true);
	while ((size_t)fid->flag[M_WIDTH] > len + i++)
		write(1, " ", 1);
	if (fid->flag[MINUS] == 0)
		_ft_pf_putptr(addr, true);
	return (ft_max(len, fid->flag[M_WIDTH]));
}
