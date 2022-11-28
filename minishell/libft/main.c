/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:21:31 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 13:09:02 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	char	**arr;

	(void)av;
	if (ac < 2)
		return (EXIT_FAILURE);
	arr = NULL;
	arr = ft_str_arr_ndup(NULL, ac - 1);
	if (arr == NULL)
		return (EXIT_FAILURE);
	ft_putarr_fd(arr, 1);
	ft_str_arr_free(arr);
	return (EXIT_SUCCESS);
}
