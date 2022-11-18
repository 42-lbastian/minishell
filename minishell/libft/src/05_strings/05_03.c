/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_03.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:06:51 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 12:31:56 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FT_STRTRIM
 * FT_STRRCHR
*/

static unsigned int	_end_checker(char const *s1, char const *set)
{
	unsigned int	len;

	len = ft_strlen(s1);
	while (ft_incharset(s1[len - 1], set))
		len--;
	return (len);
}

static char	*_fill_trim(char const *s1, char const *set, unsigned int i)
{
	unsigned int	len;
	unsigned int	j;
	char			*trim;

	len = _end_checker(s1, set);
	trim = malloc(sizeof(char) * ((len - i) + 1));
	if (trim == NULL)
		return (NULL);
	j = 0;
	while (i < len)
		trim[j++] = s1[i++];
	trim[j] = '\0';
	return (trim);
}

/*
 * @brief Create a new string which is a given string without the given
 * characters.
 * @param s1: the source string
 * @param set: the characters to trim
 * @return returns a pointer to the newly created string.
*/
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
	return (_fill_trim(s1, set, i));
}

static char	*_sub_strrchr(const char *s, int c, size_t i, bool t)
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

/*
 * @brief Find the last occurence of the given character int the given string
 * @param s: the string where we search
 * @param c: the character to find
 * @return Returns a pointer to the last occurence of the character
 * c in the string s.
*/
char	*ft_strrchr(const char *s, int c)
{
	if (s[0] == '\0' && c == 0)
		return ((char *)s);
	if (c == 0 && s[0])
		return (&((char *)s)[ft_strlen(s)]);
	if (c == 0)
		return (_sub_strrchr(s, c, ft_strlen(s), false));
	else
		return (_sub_strrchr(s, c, 0, true));
}
