/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:53 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 11:41:51 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	_count_remove_quotes(char *str)
{
	int	i;
	int	size;
	int	quotes;

	size = 0;
	i = 0;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == '"' && quotes == 0)
			quotes = 1;
		else if (str[i] == '\'' && quotes == 0)
			quotes = 2;
		else if ((str[i] == '\'' && quotes == 2)
			|| (str[i] == '"' && quotes == 1))
			quotes = 0;
		else
			size++;
		i++;
	}
	return (size);
}

static char	*_remove_quotes(char *str, int i, int j, int quotes)
{
	char	*temp;

	temp = malloc(sizeof(char) * (_count_remove_quotes(str) + 1));
	if (!temp)
		return (NULL);
	temp[_count_remove_quotes(str)] = '\0';
	while (str[i])
	{
		if (str[i] == '"' && quotes == 0)
			quotes = 1;
		else if (str[i] == '\'' && quotes == 0)
			quotes = 2;
		else if ((str[i] == '\'' && quotes == 2)
			|| (str[i] == '"' && quotes == 1))
			quotes = 0;
		else
		{
			temp[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);
	return (temp);
}

int	ms_remove_quotes(t_mslist **lst)
{
	t_mslist	*temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		(*lst)->content = _remove_quotes((*lst)->content, 0, 0, 0);
		if (!(*lst)->content)
			return (1);
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
