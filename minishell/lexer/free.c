/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:49 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/18 14:55:58 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ms_free_all(t_list **lst)
{
	ms_free_lst(lst);
}

void	ms_free_lst(t_list **lst)
{
	t_list	*temp;

	while ((*lst) && (*lst)->next)
	{
		temp = ((*lst)->next);
		if ((*lst)->content)
			free((*lst)->content);
		free((*lst));
		(*lst) = temp;
	}
	if ((*lst))
	{
		free((*lst)->content);
		free((*lst));
	}
	(*lst) = NULL;
}
