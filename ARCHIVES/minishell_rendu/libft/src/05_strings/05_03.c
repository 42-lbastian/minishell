/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_03.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:06:51 by stelie            #+#    #+#             */
/*   Updated: 2022/11/15 15:30:23 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	end_checker(char const *s1, char const *set)
{
	unsigned int	len;

	len = ft_strlen_libft(s1);
	while (ft_incharset(s1[len - 1], set))
		len--;
	return (len);
}

static char	*fill_trim(char const *s1, char const *set, unsigned int i)
{
	unsigned int	len;
	unsigned int	j;
	char			*trim;

	len = end_checker(s1, set);
	trim = malloc(sizeof(char) * ((len - i) + 1));
	if (trim == NULL)
		return (NULL);
	j = 0;
	while (i < len)
		trim[j++] = s1[i++];
	trim[j] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;

	i = 0;
	if (!s1)
		return (ft_strdup(""));
	else if (!set)
		return (ft_strdup(s1));
	else
	{
		while (ft_incharset(s1[i], set))
			i++;
		if (!s1[i])
			return (ft_strdup(""));
	}
	return (fill_trim(s1, set, i));
}

static char	*sub_strrchr(const char *s, int c, size_t i, t_bool t)
{
	char	*str;

	str = NULL;
	if (t)
	{
		while (s[i])
		{
			if (s[i] == (char)c)
				str = ((char *)s) + i;
			i++;
		}
	}
	else
	{
		while (s[i - 1])
		{
			if (s[i] == (char)c)
				str = ((char *)s) + i;
			i--;
		}
	}
	return (str);
}

char	*ft_strrchr(const char *s, int c)
{
	if (s[0] == '\0' && c == 0)
		return ((char *)s);
	if (c == 0 && s[0])
		return (&((char *)s)[ft_strlen_libft(s)]);
	if (c == 0)
		return (sub_strrchr(s, c, ft_strlen_libft(s), FALSE));
	else
		return (sub_strrchr(s, c, 0, TRUE));
}
