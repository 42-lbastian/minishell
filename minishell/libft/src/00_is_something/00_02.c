/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:15:21 by krozis            #+#    #+#             */
/*   Updated: 2022/11/18 11:12:00 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Tells if a character is a lowercase letter.
 * @return returns true if c is a lowercase letter, false if not.
*/
bool	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (true);
	return (false);
}

/*
 * @brief Tells if a character is an uppercase letter.
 * @return returns true if c is an uppercase letter, false if not.
*/
bool	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (true);
	return (false);
}
