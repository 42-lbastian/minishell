/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:20:59 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 11:10:46 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Tells if a character is a number (0 to 9).
 * @return returns true if c is a number, false if not.
*/
bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

/*
 * @brief Tells if a character is an hexadecimal number (uppercase
 * and lowercase).
 * @return returns true if c is an hexa number, false if not.
*/
bool	ft_ishexa(char *nbr)
{
	while (*nbr)
	{
		if (ft_incharset(ft_ctoupper(*nbr), HEXA_UP) == false)
			return (false);
		nbr++;
	}
	return (true);
}

/*
 * @brief Tells if a character is an octal number (0 to 7).
 * @return returns true if c is an octal number, false if not.
*/
bool	ft_isoctal(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '7'))
			return (false);
		str++;
	}
	return (true);
}

/*
 * @brief Tells if a character is printable character.
 * @return returns true if c is printable, false if not.
*/
bool	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (true);
	return (false);
}

/*
 * @brief Tells if a character is space character (space, tab, etc..).
 * @return returns true if c is a space character, false if not.
*/
bool	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (true);
	return (false);
}
