/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:05:59 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 13:16:07 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pf_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("214748364", 1);
		n = 8;
	}
	else if (n < 0)
		n = -n;
	if (n < 10)
		ft_putchar_fd('0' + n, 1);
	else
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putnbr_fd(n % 10, 1);
	}
}

static int	_pf_char(int c, t_fid *fid)
{
	int	res;

	res = 0;
	if (fid->flag[M_WIDTH] < 2)
		return (write(1, &c, 1));
	else if (fid->flag[MINUS])
	{
		res += write(1, &c, 1);
		while (fid->flag[M_WIDTH] > 1)
		{
			res += write(1, " ", 1);
			fid->flag[M_WIDTH]--;
		}
	}
	else
	{
		while (fid->flag[M_WIDTH] > 1)
		{
			res += write(1, " ", 1);
			fid->flag[M_WIDTH]--;
		}
		res += write(1, &c, 1);
	}
	return (res);
}

int	use_fid(va_list list, t_fid *fid)
{
	if (fid->conv == 'c')
		return (_pf_char(va_arg(list, int), fid));
	if (fid->conv == 's')
		return (pf_string(va_arg(list, char *), fid));
	if (fid->conv == 'i' || fid->conv == 'd')
		return (pf_int(va_arg(list, int), fid));
	if (fid->conv == 'u')
		return (pf_uint(va_arg(list, unsigned int), fid));
	if (fid->conv == 'x' || fid->conv == 'X')
		return (pf_hexa(va_arg(list, unsigned int), fid));
	if (fid->conv == 'p')
		return (pf_ptr(va_arg(list, uintptr_t), fid));
	return (ERROR);
}
