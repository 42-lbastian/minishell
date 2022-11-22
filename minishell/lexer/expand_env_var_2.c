/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <lbastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:22:41 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/22 14:22:50 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_size_env_var(t_env *st, char *str, int index, int fact)
{
	int		lenght;
	int		start;
	char	*temp;
	int		size;

	size = 0;
	start = ms_start_read_var(str, index);
	lenght = ms_lenght_read_var(str, index);
	if (lenght == 0 && fact == 1)
		return (index + 1);
	if (fact == 1)
		return (start + lenght);
	temp = ft_substr(str, start + 1, lenght);
	while (st)
	{
		if (ft_strcmp(st->var, temp) == 0)
		{
			size = ms_strlen(st->value);
			break ;
		}
		st = st->next;
	}
	free(temp);
	return (size);
}

int	ft_split_expand(t_list **lst, char **split)
{
	int	i;

	i = 1;
	if (!split)
		return (1);
	(*lst)->content = ms_strjoin_2(((*lst)->content), split[0]);
	free(split[0]);
	while (split[i])
	{
		if (ms_lstadd(lst, ms_lst_new_join(split[i], CMD)))
			return (1);
		(*lst) = (*lst)->next;
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

int	ft_error_return(char *str)
{
	free(str);
	return (1);
}
