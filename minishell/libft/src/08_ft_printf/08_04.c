/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_04.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:57:08 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 13:26:26 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_pf_putuint(unsigned int nb)
{
	if (nb < 10)
		ft_putchar_fd(nb + '0', 1);
	else
	{
		_pf_putuint(nb / 10);
		_pf_putuint(nb % 10);
	}
}

static void	_pf_uint_print(unsigned int nb, t_fid *fid, int nb_len)
{
	while (nb_len++ < fid->flag[PREC])
		write(1, "0", 1);
	if (!(fid->def_pre && fid->flag[PREC] == 0 && nb == 0))
		_pf_putuint(nb);
}

int	pf_uint(unsigned int nb, t_fid *fid)
{
	int	nb_len;
	int	i;

	i = 0;
	nb_len = ft_nbrlen(nb);
	if (fid->def_pre && fid->flag[PREC] == 0 && nb == 0)
		nb_len = 0;
	if (fid->flag[MINUS])
		_pf_uint_print(nb, fid, nb_len);
	while ((fid->flag[M_WIDTH] > fid->flag[PREC] + i)
		&& (fid->flag[M_WIDTH] > nb_len + i))
	{
		if (fid->flag[ZERO])
			i += write(1, "0", 1);
		else
			i += write(1, " ", 1);
	}
	if (fid->flag[MINUS] == 0)
		_pf_uint_print(nb, fid, nb_len);
	return (ft_max(nb_len, ft_max(fid->flag[M_WIDTH], fid->flag[PREC])));
}
