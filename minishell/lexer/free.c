/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:49 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/16 20:08:50 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_all(t_list **lst)
{
	ft_free_lst(lst);
}

void	ft_free_lst(t_list **lst)
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
