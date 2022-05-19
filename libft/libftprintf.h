/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:22:22 by hspriet           #+#    #+#             */
/*   Updated: 2021/12/14 18:39:09 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

void	ft_putchar(char c, int *res);
void	ft_putstr(char *str, int *res);
void	type_of(va_list list, char c, int *res);
int		ft_printf(const char *s, ...);
void	ft_uputnbr(unsigned int n, int *res);
void	ft_putnbr(long int n, int *res);
void	ft_putnbr_base2(unsigned long int n, int *res);
void	ft_putnbr_base(unsigned long int n, int *res);

#endif
