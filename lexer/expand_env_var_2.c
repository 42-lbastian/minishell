/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:22:41 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/12 19:08:15 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_split_expand(char *temp, t_mslist **lst, char **split)
{
	int	i;

	i = 1;
	free(temp);
	if (!split)
		return (1);
	(*lst)->content = ms_strjoin_2(((*lst)->content), split[0]);
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

int	ms_error_return(char *str)
{
	free(str);
	return (1);
}