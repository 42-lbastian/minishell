/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:07:58 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 13:02:59 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_MEMMOVE
 * FT_MEMSET  --  NOT DOCUMENTED
 * FT_MEMCHR  --  NOT DOCUMENTED
 * FT_MEMCMP  --  NOT DOCUMENTED
 * FT_MEMCPY  --  NOT DOCUMENTED
*/

/*
 * @brief Copies the n bytes from memory area 'src' to the memory area 'dest'.
 * @return Returns a pointer to 'dest'.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (dest);
	if (src < dest)
	{
		while (i < n)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*
 * @brief Fills the first n bytes of the memory area pointed to by s with
 * the constant byte c.
 * @return Returns a pointer to the memory area 's'.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = s;
	while (n--)
		*str++ = (char)c;
	return (s);
}

/*
 * @brief Fills the first n bytes of the memory area pointed to by s with
 * the constant byte c.
 * @return Returns a pointer to the memory area 's'.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}

/*
 * @brief Scans the initial n bytes of the memory area pointed to by s
 * for the first instance of c.  Both c and the bytes of the memory area
 * pointed to by s are interpreted as unsigned char.
 * @return Returns a pointer to the matching byte or NULL if the character
 * does not occur in the given memory area.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
 * @brief Copies n bytes from memory area src to memory area dest. 
 * The memory areas must not overlap.  Use ft_memmove if the memory
 * areas do overlap.
 * @return Returns a pointer to 'dest'.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;

	if (dest == 0 && src == 0)
		return (dest);
	str = dest;
	i = 0;
	while (i < n)
	{
		str[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
