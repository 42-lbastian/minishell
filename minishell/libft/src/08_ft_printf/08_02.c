/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:22:09 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 13:16:36 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_pf_str_null(int width)
{
	int	i;

	i = 6;
	while (width > i++)
		write(1, " ", 1);
	write(1, "(null)", 6);
	return (ft_max(6, width));
}

static int	_pf_str_with_prec(char *str, t_fid *fid)
{
	int	res;

	res = fid->flag[M_WIDTH] - fid->flag[PREC];
	if (res < 0)
		return (write(1, str, fid->flag[PREC]));
	else if (fid->flag[MINUS] == 0)
	{
		while (res)
		{
			write(1, " ", 1);
			res--;
		}
		write(1, str, fid->flag[PREC]);
	}
	else
	{
		write(1, str, fid->flag[PREC]);
		while (res)
		{
			write(1, " ", 1);
			res--;
		}
	}
	return (fid->flag[M_WIDTH]);
}

static int	_pf_str_no_prec(char *str, t_fid *fid, int len)
{
	int	res;

	res = fid->flag[M_WIDTH] - len;
	if (res < 0)
		return (write(1, str, len));
	else if (fid->flag[MINUS] == 0)
	{
		while (res)
		{
			write(1, " ", 1);
			res--;
		}
		write(1, str, len);
	}
	else
	{
		write(1, str, len);
		while (res)
		{
			write(1, " ", 1);
			res--;
		}
	}
	return (fid->flag[M_WIDTH]);
}

int	pf_string(char *str, t_fid *fid)
{
	if (!str)
		str = "(null)";
	if (!str)
		return (_pf_str_null(fid->flag[M_WIDTH]));
	if (fid->def_pre == false || (fid->flag[PREC] >= (int)ft_strlen(str)))
		return (_pf_str_no_prec(str, fid, ft_strlen(str)));
	return (_pf_str_with_prec(str, fid));
}
