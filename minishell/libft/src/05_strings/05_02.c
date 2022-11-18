/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:26:37 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 12:24:02 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_STRLCPY
 * FT_STRMAPI  --  NOT DOCUMENTED
 * FT_STRNCMP
 * FT_STRNSTR  --  NOT DOCUMENTED
 * FT_SUBSTR  --  NOT DOCUMENTED
*/

/*
 * @brief Copy up to size - 1 characters from the NUL-terminated string src
 * to dst, NUL-terminating the result.
 * @return Returns the total length of the string it tried to create (it
 * means the length of the string 'src').
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
 * @brief Compares the n characters of two strings.
 * @return returns an integer indicating the result of
 * the comparison (s1[i] - s2[i] where i < n).
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < (n - 1) && (((unsigned char *)s1)[i] && ((unsigned char *)s1)[i])
	&& (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]))
	{
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!s1[0] && !s2[0])
		return (&((char *)s1)[0]);
	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s1[i + j] == s2[j] && s2[j] && (i + j < len))
			j++;
		if (!s2[j])
			return (&((char *)s1)[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (len > size)
		len = size;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
