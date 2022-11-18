/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:16:15 by hspriet           #+#    #+#             */
/*   Updated: 2021/12/14 18:39:45 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

void	ft_uputnbr(unsigned int n, int *res)
{
	char	c;

	if (n < 10)
	{
		c = n % 10 + 48;
		ft_putchar(c, res);
	}
	if (n >= 10)
	{
		ft_uputnbr(n / 10, res);
		c = n % 10 + 48;
		ft_putchar(c, res);
	}
}

void	ft_putnbr(long int n, int *res)
{
	char	c;

	if (n < 0)
	{
		ft_putchar('-', res);
		n = n * -1;
	}
	if (n < 10)
	{
		c = n % 10 + 48;
		ft_putchar(c, res);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, res);
		c = n % 10 + 48;
		ft_putchar(c, res);
	}
}

void	ft_putnbr_base2(unsigned long int n, int *res)
{	
	char	c;
	char	*base;

	base = "0123456789ABCDEF";
	if (n < 16)
	{
		c = base[n % 16];
		ft_putchar(c, res);
	}
	if (n >= 16)
	{
		ft_putnbr_base2(n / 16, res);
		c = base[n % 16];
		ft_putchar(c, res);
	}
}

void	ft_putnbr_base(unsigned long int n, int *res)
{	
	char	c;
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
	{
		c = base[n % 16];
		ft_putchar(c, res);
	}
	if (n >= 16)
	{
		ft_putnbr_base(n / 16, res);
		c = base[n % 16];
		ft_putchar(c, res);
	}
}
