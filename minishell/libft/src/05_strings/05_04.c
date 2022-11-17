/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_04.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:02:15 by stelie            #+#    #+#             */
/*   Updated: 2022/11/17 16:32:19 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ctolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	ft_ctoupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*ft_str_cut_before(char *src, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dest = malloc(sizeof(char) * (i));
	if (dest == NULL)
		return (NULL);
	dest[i] = '\0';
	while (--i >= 0)
		dest[i] = src[i];
	return (dest);
}

char	*ft_str_cut_after(char *src, char c)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] && src[i] != c)
		i++;
	if (src[0] == c)
	{
		dest = ft_strdup(src + 1);
		return (dest);
	}
	else
		dest = malloc(sizeof(char) * ((ft_strlen_libft(src) - i) + 1));
	if (dest == NULL)
		return (NULL);
	while (src[++i])
		dest[j++] = src[i];
	dest[j] = '\0';
	return (dest);
}

/*
 * @brief Compares two strings
 * @return returns an integer indicating the result of
 * the comparison (*s1 - *s2).
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-*s2);
	if (!s2)
		return (*s1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == 0 && *s2 == 0)
		return (0);
	else if (*s2 == 0)
		return (*s1);
	else if (*s1 == 0)
		return (-*s2);
	return (*s1 - *s2);
}
