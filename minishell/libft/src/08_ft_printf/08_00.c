/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:34:41 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 13:15:46 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_check_if_valid_fid(t_fid *fid)
{
	if (!(ft_incharset(fid->conv, TYPESET)))
		fid->flag[FID_ERROR] = 1;
	if (fid->flag[ZERO] && ((fid->conv == 'c' || fid->conv == 's'
				|| fid->conv == 'p') || fid->flag[MINUS] == 1))
		fid->flag[FID_ERROR] = 1;
	if (fid->flag[SHARP] && !(fid->conv == 'x' || fid->conv == 'X'))
		fid->flag[FID_ERROR] = 1;
	if (fid->flag[PLUS] && (!(fid->conv == 'i' || fid->conv == 'd')
			|| fid->flag[SPAC] == 1))
		fid->flag[FID_ERROR] = 1;
	if (fid->flag[SPAC] && !(fid->conv == 'i' || fid->conv == 'd'))
		fid->flag[FID_ERROR] = 1;
	if (fid->flag[PREC] > 0 && (fid->conv == 'c' || fid->conv == 'p'))
		fid->flag[FID_ERROR] = 1;
	if (fid->flag[ZERO] && fid->flag[PREC] > 0)
		fid->flag[FID_ERROR] = 1;
}

static void	_check_if_valid_flag(char c, t_fid *fid)
{
	if (c == '0' && fid->flag[ZERO] == 0)
		fid->flag[ZERO] = 1;
	else if (c == '#' && fid->flag[SHARP] == 0)
		fid->flag[SHARP] = 1;
	else if (c == '-' && fid->flag[MINUS] == 0)
		fid->flag[MINUS] = 1;
	else if (c == '+' && fid->flag[PLUS] == 0)
		fid->flag[PLUS] = 1;
	else if (c == ' ' && fid->flag[SPAC] == 0)
		fid->flag[SPAC] = 1;
	else
		fid->flag[FID_ERROR] = 1;
	if (fid->flag[PLUS] && fid->flag[SPAC])
		fid->flag[FID_ERROR] = 1;
	if (fid->flag[MINUS] && fid->flag[ZERO])
		fid->flag[FID_ERROR] = 1;
}

static void	_get_fid(const char *format, t_fid *fid)
{
	while (ft_incharset(*format, FLAGSET))
	{
		_check_if_valid_flag(*format, fid);
		format++;
		fid->fid_len++;
	}
	if (ft_isdigit(*format))
	{
		fid->flag[M_WIDTH] = ft_atoi(format);
		while (ft_isdigit(*format) && format++)
			fid->fid_len++;
	}
	if (*format == '.')
	{
		fid->def_pre = true;
		format++;
		fid->fid_len++;
		fid->flag[PREC] = ft_atoi(format);
		while (ft_isdigit(*format) && format++)
			fid->fid_len++;
	}
	fid->conv = *format;
	format++;
	fid->fid_len++;
}

static int	_found_fid(va_list list, const char *format, int *pf_res)
{
	t_fid	fid;

	ft_bzero(&fid, sizeof(t_fid));
	if (*format && *format == '%')
	{
		*pf_res += 1;
		return (write(1, "%", 1));
	}
	else
	{
		_get_fid(format, &fid);
		_check_if_valid_fid(&fid);
		if (fid.flag[FID_ERROR])
			return (ERROR);
		*pf_res += use_fid(list, &fid);
	}
	return (fid.fid_len);
}

/*
 * @brief Produce output on STDOUT according to a format given by user.
 * Working flags are '#0-+' and the space ' '.
 * Working conversions are "csiduxXp%" and min width and precision are working.
 * @return Returns as an int the number of characters printed by ft_printf.
*/
int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		pf_res;
	int		fid_len;

	pf_res = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			fid_len = _found_fid(list, format + 1, &pf_res);
			if (fid_len == ERROR)
				return (ERROR);
			format += fid_len;
		}
		else
			pf_res += write(1, format, 1);
		format++;
	}	
	va_end(list);
	return (pf_res);
}
