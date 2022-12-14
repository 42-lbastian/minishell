/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:10:46 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 11:15:07 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief used in expand_env_var.c
*/
char	*ms_strjoin_c(char *str, char c)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	if (str)
		size = ms_strlen(str);
	else
		size = 0;
	dest = malloc(sizeof(char) * (size + 2));
	if (!dest)
		return (NULL);
	while (str && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
	if (str)
		free(str);
	return (dest);
}

static char	*_malloc_strjoin_2(char *str1, char *str2)
{
	char	*dest;

	if (!str1)
		dest = malloc(sizeof(char) * (ms_strlen(str2) + 1));
	else
		dest = malloc(sizeof(char) * (ms_strlen(str1) + ms_strlen(str2) + 1));
	if (!dest)
		return (NULL);
	return (dest);
}

/*
 * @brief used in expand_env_var.c && expand_env_var_2.c
*/
char	*ms_strjoin_2(char *str1, char *str2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = _malloc_strjoin_2(str1, str2);
	if (!dest)
		return (NULL);
	while (str1 && str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	while (str2 && str2[j])
	{
		dest[i + j] = str2[j];
		j++;
	}
	dest[i + j] = '\0';
	if (str1)
		free(str1);
	free(str2);
	return (dest);
}
