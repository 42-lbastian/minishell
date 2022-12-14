/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:08 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/28 16:43:39 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_count_remove_quotes(char *str)
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

int	ms_count_char(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] && !ft_incharset(str[i], C_CHECK_CHAR))
				while (str[i] && !ft_incharset(str[i], C_CHECK_CHAR))
					i++;
			else
				size++;
		}
		else if (str[i] == '\'' || str[i] == '"')
			i++;
		else
		{
			i++;
			size++;
		}
	}
	return (size);
}

int	ms_lenght_read_var(char *str, int index)
{
	int	i;
	int	size;

	i = index;
	size = 0;
	while (i < ms_strlen(str))
	{
		while (str[i] == '"' || str[i] == '\'')
			i++;
		if (str[i] && str[i] == '$')
		{
			size++;
			i++;
			while (str[i] && str[i] != '"' && str[i] != '\''
				&& str[i] != '$' && str[i] != ' ')
			{
				size++;
				i++;
			}
			return (size - 1);
		}
		else
			i++;
	}
	return (size);
}

int	ms_start_read_var(char *str, int index)
{
	int	i;

	i = index;
	while (str[i] && str[i] != '$')
		i++;
	return (i);
}

int	ms_count_nb_quotes(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			nb++;
		i++;
	}
	return (nb);
}