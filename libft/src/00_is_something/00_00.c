/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:18:34 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 11:07:12 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Looks for a character in a given character set.
 * @param c: the char that you search
 * @param charset: the character set where you try to find c
 * @return returns true if c is found in the character set, false if not.
*/
bool	ft_incharset(char c, const char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (true);
		charset++;
	}
	return (false);
}

/*
 * @brief Tells if a character is alphanumeric.
 * @return returns true if c is an alphanumeric character, false if not.
*/
bool	ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (true);
	else if (ft_isalpha(c))
		return (true);
	return (false);
}

/*
 * @brief Tells if a character is a alphabetic (lowercase and uppercase).
 * @return returns true if c is an alphabetic character, false if not.
*/
bool	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (true);
	return (false);
}

/*
 * @brief Tells if a character is a ascii (1 to 127).
 * @return returns true if c is ascii, false if not.
*/
bool	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (true);
	return (false);
}

/*
 * @brief Tells if a character is a binary number character (0 or 1).
 * @return returns true if c is binary, false if not.
*/
bool	ft_isbinary(char *str)
{
	while (*str)
	{
		if (!(*str == '0' || *str == '1'))
			return (false);
		str++;
	}
	return (true);
}
