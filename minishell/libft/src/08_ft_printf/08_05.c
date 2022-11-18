/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_05.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:39:38 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 13:26:52 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_pf_puthexa(unsigned int nb, bool low)
{
	if (nb < 16)
	{
		if (nb <= 9)
			ft_putchar_fd('0' + nb, 1);
		else
			ft_putchar_fd('A' + (low * 32) + nb - 10, 1);
	}
	else
	{
		_ft_pf_puthexa(nb / 16, low);
		_ft_pf_puthexa(nb % 16, low);
	}
}

static void	_pf_hexa_print(unsigned int nb, t_fid *fid, int nb_len, bool low)
{
	int	i;

	i = 0;
	if (fid->flag[SHARP] && nb != 0)
	{
		i += 2;
		ft_printf("0%c", fid->conv);
	}
	if (fid->flag[ZERO])
	{
		while (fid->flag[M_WIDTH] > ft_max(nb_len, fid->flag[PREC]) + i++)
			write(1, "0", 1);
	}
	while (fid->flag[PREC] > nb_len++)
		write(1, "0", 1);
	if (!(fid->def_pre && fid->flag[PREC] == 0 && nb == 0))
		_ft_pf_puthexa(nb, low);
}

static int	_pf_hexa_default(unsigned int nb, t_fid *fid, int nb_len, bool low)
{
	int	len;
	int	i;

	i = 0;
	if (fid->flag[SHARP] && nb != 0)
		i += 2;
	len = nb_len + i;
	if (fid->flag[MINUS])
		_pf_hexa_print(nb, fid, nb_len, low);
	while (fid->flag[M_WIDTH] > nb_len + i && fid->flag[ZERO] == 0
		&& fid->flag[M_WIDTH] > fid->flag[PREC] + i)
		i += write(1, " ", 1);
	if (fid->flag[MINUS] == 0)
		_pf_hexa_print(nb, fid, nb_len, low);
	if (fid->flag[PREC] > nb_len && fid->flag[SHARP] && nb != 0)
		return (ft_max(fid->flag[PREC] + 2, fid->flag[M_WIDTH]));
	if (fid->flag[PREC] > nb_len)
		return (ft_max(fid->flag[PREC], fid->flag[M_WIDTH]));
	return (ft_max(len, fid->flag[M_WIDTH]));
}

int	pf_hexa(unsigned int nb, t_fid *fid)
{
	int		nb_len;
	bool	low;

	if (fid->conv == 'X')
		low = false;
	else
		low = true;
	nb_len = ft_hexalen(nb);
	if (fid->def_pre && fid->flag[PREC] == 0 && nb == 0)
		nb_len = 0;
	return (_pf_hexa_default(nb, fid, nb_len, low));
}
