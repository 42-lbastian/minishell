/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:22:01 by stelie            #+#    #+#             */
/*   Updated: 2022/11/15 15:30:01 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_strlen_libft(s);
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
	len = (ft_strlen_libft(s1) + ft_strlen_libft(s2));
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;

	i = 0;
	lendest = ft_strlen_libft(dst);
	if (size == 0)
		return (ft_strlen_libft(src));
	if (lendest > size - 1)
		return (size + ft_strlen_libft(src));
	while (src[i] && i + lendest < size - 1)
	{
		dst[i + lendest] = src[i];
		i++;
	}
	dst[i + lendest] = '\0';
	return (ft_strlen_libft(src) + lendest);
}
