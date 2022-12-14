/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:10:04 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 11:38:01 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	_count_spaces(char *str)
{
	int	size;
	int	i;
	int	ret;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '"' || str[i] == '\''))
		{
			ret = ms_count_read_quotes(str, i);
			i += ret + 1;
			size += ret + 1;
		}
		else if (str[i] && str[i] != ' ')
		{
			i++;
			size++;
		}
		else
			i++;
	}
	return (size);
}

static int	*_spaces_flag_loop(int *count, char *str, char **temp, char c)
{
	if (str[count[0]] && (str[count[0]] == '"' || str[count[0]] == '\''))
	{
		c = str[count[0]];
		(*temp)[count[1]] = str[count[0]];
		count[1]++;
		count[0]++;
		while (str[count[0]] != c)
		{
			(*temp)[count[1]] = str[count[0]];
			count[0]++;
			count[1]++;
		}
		(*temp)[count[1]] = str[count[0]];
		count[0]++;
		count[1]++;
	}
	else if (str[count[0]] && str[count[0]] != ' ')
	{
		(*temp)[count[1]] = str[count[0]];
		count[1]++;
		count[0]++;
	}
	else
		count[0]++;
	return (count);
}

static char	*_spaces_flag(char *str)
{
	int		*count;
	int		size;
	char	*temp;
	char	c;

	c = 0;
	count = malloc(sizeof(int) * 2);
	if (!count)
		return (NULL);
	count[0] = 0;
	count[1] = 0;
	size = _count_spaces(str);
	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
	{
		free(count);
		return (NULL);
	}
	temp[size] = '\0';
	while (str[count[0]])
		count = _spaces_flag_loop(count, str, &temp, c);
	free(str);
	free(count);
	return (temp);
}

int	ms_remove_spaces(t_mslist **lst)
{
	t_mslist	*temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		if (((*lst)->content[0] != '"' && (*lst)->content[0] != '\''))
			(*lst)->content = _spaces_flag((*lst)->content);
		if (!(*lst)->content)
			return (1);
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
