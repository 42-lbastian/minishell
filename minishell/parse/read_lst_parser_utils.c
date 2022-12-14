/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lst_parser_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:36:31 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/08 16:33:53 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_close_return(char *msg, int pip[2][2], int err)
{
	set_err_code(err);
	close(pip[1][0]);
	close(pip[1][1]);
	return (ft_putmsg_fd(msg, STDERR_FILENO, EXIT_FAILURE));
}

char	*ms_malloc_strjoin_here_doc(char *str1, char *str2)
{
	char	*dest;

	if (!str1)
		dest = malloc(sizeof(char) * (ms_strlen(str2) + 2));
	else
		dest = malloc(sizeof(char) * (ms_strlen(str1) + ms_strlen(str2) + 2));
	if (!dest)
		return (NULL);
	return (dest);
}

char	*ms_strjoin_here_doc(char *str1, char *str2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = ms_malloc_strjoin_here_doc(str1, str2);
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
	dest[i + j] = '\n';
	dest[i + j + 1] = '\0';
	if (str1)
		free(str1);
	return (dest);
}
