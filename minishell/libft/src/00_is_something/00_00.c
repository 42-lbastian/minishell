/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:18:34 by stelie            #+#    #+#             */
/*   Updated: 2022/11/17 15:57:54 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Looks for a character in a given character set.
 * @param c: the char that you search
 * @param charset: the character set where you try to find c
 * @return returns TRUE if c is found in the character set, FALSE if not.
*/
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

/*
 * @brief Tells if a character is alphanumeric.
 * @return returns TRUE if c is an alphanumeric character, FALSE if not.
*/
t_bool	ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (TRUE);
	else if (ft_isalpha(c))
		return (TRUE);
	return (FALSE);
}

/*
 * @brief Tells if a character is a alphabetic (lowercase and uppercase).
 * @return returns TRUE if c is an alphabetic character, FALSE if not.
*/
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
