/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_05.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:36:30 by stelie            #+#    #+#             */
/*   Updated: 2022/11/22 13:51:24 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_STR_ARR_LEN
 * FT_STR_ARR_DUP
 * FT_STR_ARR_FREE
 * FT_STR_FREE
*/

/*
 * @brief Calculates the length of a given array (char **).
 * @return Returns the size in a size_t variable.
*/
size_t	ft_str_arr_len(char **array)
{
	size_t	len;

	len = 0;
	while (array && array[len])
		len++;
	return (len);
}

/*
 * @brief Applies a ft_strdup for an entire array (char **)
 * @param array: the str array to duplicate
 * @return Returns a pointer to the duplicated array.
*/
char	**ft_str_arr_dup(char	**array)
{
	char	**copy;
	int		i;

	if (array == NULL)
		return (NULL);
	copy = ft_calloc(ft_str_arr_len(array) + 1, sizeof(*copy));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (array[i])
	{
		copy[i] = ft_strdup(array[i]);
		i++;
	}
	return (copy);
}

/*
 * @brief Frees an allocated NULL-terminated string array.
 * @param array: a pointer to the string array you want to free
*/
void	ft_str_arr_free(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		ft_str_free((array)[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

/*
 * @brief Frees an allocated string and set pointer to NULL.
*/
void	ft_str_free(char *str)
{
	free(str);
	str = NULL;
}
