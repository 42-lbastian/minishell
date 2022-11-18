/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:18:34 by stelie            #+#    #+#             */
/*   Updated: 2022/04/19 20:45:22 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_incharset(char c, const char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (TRUE);
		charset++;
	}
	return (FALSE);
}

t_bool	ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (TRUE);
	else if (ft_isalpha(c))
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isbinary(char *str)
{
	while (*str)
	{
		if (!(*str == '0' || *str == '1'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
