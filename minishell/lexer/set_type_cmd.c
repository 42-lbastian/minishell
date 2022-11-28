/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:10:11 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/28 13:54:41 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_set_type_cmd(t_mslist **lst)
{
	t_mslist	*temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		if ((*lst)->next && (*lst)->next->type == CMD
			&& (*lst)->type == FILE_IN)
			(*lst)->next->type = ARG_FILE_IN;
		else if ((*lst)->next && (*lst)->next->type == CMD
			&& (*lst)->type == FILE_OUT_OVER)
			(*lst)->next->type = ARG_FILE_OUT_OVER;
		else if ((*lst)->next && (*lst)->next->type == CMD
			&& (*lst)->type == FILE_OUT_APP)
			(*lst)->next->type = ARG_FILE_OUT_APP;
		else if ((*lst)->next && (*lst)->next->type == CMD
			&& (*lst)->type == HERE_DOC)
			(*lst)->next->type = LIMITOR;
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
