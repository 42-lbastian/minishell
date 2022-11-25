/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:57:06 by stelie            #+#    #+#             */
/*   Updated: 2022/11/25 11:42:19 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Puts a given string array in the given fd.
 * Each string is separated by a '\n'.
*/
void	ft_putarr_fd(char **array, int fd)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		ft_putstr_fd(array[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}
