/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:22:01 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 12:31:14 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_STRCHR
 * FT_STRDUP
 * FT_STRITERI
 * FT_STRJOIN
 * FT_STRLCAT
*/

/*
 * @brief Find the first occurence of the given character int the given string
 * @param s: the string where we search
 * @param c: the character to find
 * @return Returns a pointer to the first occurence of the character
 * c in the string s.
*/
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s[0] == '\0' && c == '\0')
		return ((char *)s);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
		if (c == 0 && !s[i])
			return (&((char *)s)[i]);
	}
	return (NULL);
}

/*
 * @brief Duplicate a given string
 * @param s: the string to duplicate
 * @return Returns a pointer to the new string, which is a
 * duplicate of the string s
*/
char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
 * @brief Applies the given function to each character of the given string
 * @param s: the string to iterate
 * @param (*f): the function to apply to each character of the string s
 * and its index
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, s + i);
		i++;
	}
}

/*
 * @brief Creates a new string which is the joining of two given strings.
 * @return Returns a pointer to the new string.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;
	int		i;

	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len = (ft_strlen(s1) + ft_strlen(s2));
	join = malloc(sizeof(char) * (len + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *(s1++);
	while (*s2)
		join[i++] = *(s2++);
	join[i] = '\0';
	return (join);
}

/*
 * @brief Concatenate a given maximum characters of two given strings into one,
 * with the guarantee of a NUL-terminating result.
 * @return Returns the total size of the string it tried to create.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;

	i = 0;
	lendest = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	if (lendest > size - 1)
		return (size + ft_strlen(src));
	while (src[i] && i + lendest < size - 1)
	{
		dst[i + lendest] = src[i];
		i++;
	}
	dst[i + lendest] = '\0';
	return (ft_strlen(src) + lendest);
}
