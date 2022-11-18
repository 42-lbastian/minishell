/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:10:04 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/18 14:55:24 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ms_count_spaces(char *str)
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

char	*ft_spaces_flag(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*temp;
	char	c;

	i = 0;
	j = 0;
	size = ms_count_spaces(str);
	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (NULL);
	temp[size] = '\0';
	while (str[i])
	{
		if (str[i] && (str[i] == '"' || str[i] == '\''))
		{
			c = str[i];
			temp[j] = str[i];
			j++;
			i++;
			while (str[i] != c)
			{
				temp[j] = str[i];
				i++;
				j++;
			}
			temp[j] = str[i];
			i++;
			j++;
		}
		else if (str[i] && str[i] != ' ')
		{
			temp[j] = str[i];
			j++;
			i++;
		}
		else
			i++;
	}
	free(str);
	return (temp);
}

int	ms_remove_spaces(t_list **lst)
{
	t_list	*temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		if (((*lst)->content[0] != '"' && (*lst)->content[0] != '\''))
			(*lst)->content = ft_spaces_flag((*lst)->content);
		if (!(*lst)->content)
			return (1);
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
