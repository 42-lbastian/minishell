/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_06.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:30:54 by stelie            #+#    #+#             */
/*   Updated: 2022/11/27 20:05:03 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_STRREV
 * FT_STR_RM_CHAR
 * FT_STR_RM_FST_OCC
 * FT_STR_RM_LAST_OCC
*/

/*
 * @brief Creates a string which is the reverse of the given string.
 * Example: "STRING" -> "GNIRTS"
 * @return Returns a pointer to the newly created string.
*/
char	*ft_strrev(char	*str)
{
	char	*rev;
	int		i;
	int		j;

	if (str == NULL)
		return (str);
	j = 0;
	i = ft_strlen(str);
	rev = malloc(sizeof(char) * (i + 1));
	if (rev == NULL)
		return (NULL);
	i--;
	while (j <= i)
	{
		rev[j] = str[i - j];
		j++;
	}
	rev[j] = '\0';
	return (rev);
}

static void	_ft_fill(char *dest, char *src, int index)
{
	int	i;

	i = 0;
	while (i != index)
	{
		dest[i] = src[i];
		i++;
	}
	while (src[++i])
		dest[i - 1] = src[i];
	dest[i - 1] = '\0';
}

/*
 * @brief Removes the character in the given string at index given.
 * @param src: the string where to remove a char
 * @param index: the index of the char to remove
 * @return Returns a pointer to the newly created string.
 * \/!\ CARE, THE SOURCE STRING IS FREED !
 */
char	*ft_str_rm_char(char *src, int index)
{
	char	*dest;

	dest = NULL;
	if (index < 0 || (size_t)index >= ft_strlen(src))
		return (src);
	dest = malloc(sizeof(char) * ft_strlen(src));
	if (dest == NULL)
		return (NULL);
	_ft_fill(dest, src, index);
	ft_free(src);
	return (dest);
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
