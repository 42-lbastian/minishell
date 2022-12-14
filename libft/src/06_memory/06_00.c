/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:13:51 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 12:46:44 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_BZERO
 * FT_CALLOC
 * FT_FREE
*/

/*
 * @brief Erase the data in the n bytes of the memory starting at the
 * location pointed by s, writing zeros to that area.
*/
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/*
 * @brief Allocate memory or an array of nmemb elements of size
 * bytes each and set the memory to zero.
 * @return Returns a pointer to the allocated memory.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*obj;

	obj = malloc(nmemb * size);
	if (obj == NULL)
		return (NULL);
	ft_bzero(obj, nmemb * size);
	return (obj);
}

/*
 * @brief Verifies if a the given pointer is an allocated memory,
 * frees it and set it to NULL.
*/
void	ft_free(void *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}

/*
 * @brief Verifies if a the given pointer is an allocated memory,
 * frees it and set it to NULL.
 * @return Returns the given return value.
*/
int	ft_free_and_return(void *p, int return_value)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
	return (return_value);
}
