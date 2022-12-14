/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_03.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:39:25 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 13:26:07 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_pf_int_print(int nb, t_fid *fid, int nb_len)
{
	if (nb < 0)
		write(1, "-", 1);
	else if (fid->flag[PLUS])
		write(1, "+", 1);
	else if (fid->flag[SPAC])
		write(1, " ", 1);
	while (fid->flag[PREC] > nb_len)
	{
		write(1, "0", 1);
		nb_len++;
	}
	if (!(fid->def_pre && fid->flag[PREC] == 0))
		ft_pf_putnbr(nb);
}

static int	_pf_int_default(int nb, t_fid *fid, int nb_len)
{
	int	i;

	i = 0;
	if (fid->flag[MINUS])
		_pf_int_print(nb, fid, nb_len);
	while (fid->flag[M_WIDTH] > nb_len + i
		&& fid->flag[M_WIDTH] > fid->flag[PREC] + i)
	{
		if (fid->flag[ZERO])
			i += write(1, "0", 1);
		else
			i += write(1, " ", 1);
	}
	if (fid->flag[MINUS] == 0)
		_pf_int_print(nb, fid, nb_len);
	return (ft_max(nb_len, ft_max(fid->flag[M_WIDTH], fid->flag[PREC])));
}

static int	_pf_int_sign_zero(int nb, t_fid *fid, int nb_len)
{
	int	max;
	int	i;

	i = 1;
	max = ft_max(nb_len, fid->flag[M_WIDTH]);
	if (nb < 0)
		write(1, "-", 1);
	else if (fid->flag[PLUS])
		write(1, "+", 1);
	else if (fid->flag[SPAC])
		write(1, " ", 1);
	while (fid->flag[M_WIDTH] > nb_len + i++)
		write(1, "0", 1);
	ft_pf_putnbr(nb);
	if (max == nb_len)
		return (max + 1);
	return (max);
}

static int	_pf_int_sign_simple(int nb, t_fid *fid, int nb_len)
{
	int	i;
	int	max;

	i = 1;
	max = ft_max(nb_len, ft_max(fid->flag[M_WIDTH], fid->flag[PREC]));
	if (fid->flag[MINUS])
		_pf_int_print(nb, fid, nb_len);
	while (fid->flag[M_WIDTH] > nb_len + i
		&& fid->flag[M_WIDTH] > fid->flag[PREC] + i)
	{
		if (fid->flag[ZERO])
			i += write(1, "0", 1);
		else
			i += write(1, " ", 1);
	}
	if (fid->flag[MINUS] == 0)
		_pf_int_print(nb, fid, nb_len);
	if (max == fid->flag[PREC] || max == nb_len)
		return (max + 1);
	return (max);
}

int	pf_int(int nb, t_fid *fid)
{
	int	nb_len;

	nb_len = ft_nbrlen(nb);
	if (fid->def_pre && fid->flag[PREC] == 0)
		nb_len = 0;
	if (nb == 0 && fid->def_pre == false && fid->flag[M_WIDTH] < 2)
	{
		if (fid->flag[PLUS])
			return (write(1, "+0", 2));
		else if (fid->flag[SPAC])
			return (write(1, " 0", 2));
		return (write(1, "0", 1));
	}
	if (nb < 0 || fid->flag[SPAC] || fid->flag[PLUS])
	{
		if (fid->flag[ZERO])
			return (_pf_int_sign_zero(nb, fid, nb_len));
		return (_pf_int_sign_simple(nb, fid, nb_len));
	}
	return (_pf_int_default(nb, fid, nb_len));
}
