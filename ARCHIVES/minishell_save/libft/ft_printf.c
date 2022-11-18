/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:26:06 by hspriet           #+#    #+#             */
/*   Updated: 2021/12/14 18:39:26 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

void	ft_putchar(char c, int *res)
{
	write(1, &c, 1);
	*res = *res + 1;
}

void	ft_putstr(char *str, int *res)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", res);
	}
	else
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			*res = *res + 1;
			i++;
		}
	}
	i--;
}

void	type_of(va_list list, char c, int *res)
{
	if (c == 'c')
		ft_putchar(va_arg(list, int), res);
	if (c == 's')
		ft_putstr(va_arg(list, char *), res);
	if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(list, int), res);
	if (c == 'u')
		ft_uputnbr(va_arg(list, unsigned int), res);
	if (c == 'x')
		ft_putnbr_base(va_arg(list, unsigned int), res);
	if (c == 'X')
		ft_putnbr_base2(va_arg(list, unsigned int), res);
	if (c == 'p')
	{
		ft_putstr("0x", res);
		ft_putnbr_base(va_arg(list, unsigned long int), res);
	}
	if (c == '%')
		ft_putchar('%', res);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	list;
	int		res;

	i = 0;
	res = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			type_of(list, s[i], &res);
		}
		else
		{
			ft_putchar(s[i], &res);
		}
		i++;
	}
	va_end(list);
	return (res);
}
