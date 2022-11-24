/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_06.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:30:54 by stelie            #+#    #+#             */
/*   Updated: 2022/11/24 11:09:28 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_fill(char *dest, char *src, int is_c)
{
	int	i;

	i = 0;
	while (i != is_c)
	{
		dest[i] = src[i];
		i++;
	}
	while (src[++i])
		dest[i - 1] = src[i];
	dest[i - 1] = '\0';
}

/*
 * @brief Remove the first occurence in of a given char in the given string.
 * @param src: the string where to remove the given char.
 * @param c: the character to remove (once only)
 * @return Returns a pointer to the newly created string.
 * \/!\ CARE, THE SOURCE STRING IS FREED !
 */
char	*ft_str_rm_fst_occ(char *src, char c)
{
	char	*dest;
	int		i;
	int		is_c;

	i = 0;
	is_c = -1;
	dest = NULL;
	while (src && src[i])
	{
		if (src[i] == c)
		{
			is_c = i;
			break ;
		}
		i++;
	}
	if (is_c < 0)
		return (src);
	dest = malloc(sizeof(char) * strlen(src));
	if (dest == NULL)
		return (NULL);
	_ft_fill(dest, src, is_c);
	ft_free(src);
	return (dest);
}

/*
 * @brief Remove the last occurence in of a given char in the given string.
 * @param src: the string where to remove the given char.
 * @param c: the character to remove (once only)
 * @return Returns a pointer to the newly created string.
 * \/!\ CARE, THE SOURCE STRING IS FREED !
 */
char	*ft_str_rm_last_occ(char *src, char c)
{
	char	*dest;
	int		i;
	int		is_c;

	i = ft_strlen(src) - 1;
	is_c = -1;
	dest = NULL;
	while (src && src[i])
	{
		if (src[i] == c)
		{
			is_c = i;
			break ;
		}
		i--;
	}
	if (is_c < 0)
		return (src);
	dest = malloc(sizeof(char) * strlen(src));
	if (dest == NULL)
		return (NULL);
	_ft_fill(dest, src, is_c);
	ft_free(src);
	return (dest);
}
