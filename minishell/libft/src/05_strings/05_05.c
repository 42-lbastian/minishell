/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_05.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:36:30 by stelie            #+#    #+#             */
/*   Updated: 2022/11/25 12:22:28 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_STR_ARR_LEN
 * FT_STR_ARR_DUP
 * FT_STR_ARR_NDUP
 * FT_STR_ARR_FREE
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
char	**ft_str_arr_dup(char **array)
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
	copy[i] = NULL;
	return (copy);
}

/*
 * @brief Applies a ft_strdup for 'n' str of a given string array;
 * @param array: the str array to duplicate
 * @param n: the number of strings to dulicate
 * @return Returns a pointer to the duplicated array.
*/
char	**ft_str_arr_ndup(char **array, int n)
{
	char	**copy;
	int		i;

	if (array == NULL || n < 1)
		return (NULL);
	if (ft_str_arr_len(array) < (size_t)n)
		return (ft_str_arr_dup(array));
	copy = malloc(sizeof(char *) * (ft_min(ft_str_arr_len(array), n) + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (array[i] && i < n)
	{
		copy[i] = ft_strdup(array[i]);
		i++;
	}
	copy[i] = NULL;
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
		ft_free((array)[i]);
		i++;
	}
	ft_free(array);
}
