/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:49 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/28 16:43:39 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_free_main_s(t_struct *main_s)
{
	ms_free_lst(main_s->lst);
	ft_free(main_s);
}

void	ms_free_lst(t_mslist *lst)
{
	t_mslist	*temp;

	while (lst)
	{
		temp = (lst->next);
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = NULL;
		lst = temp;
	}
}

void	ms_free_parse(t_lst_parser **lst_parser)
{
	t_lst_parser	*temp;
	int				i;

	while ((*lst_parser))
	{
		i = 0;
		temp = (*lst_parser)->next;
		if ((*lst_parser)->type == CMD)
		{
			while ((*lst_parser)->value.cmd[i])
			{
				free((*lst_parser)->value.cmd[i]);
				i++;
			}
			free((*lst_parser)->value.cmd);
		}
		else
			free ((*lst_parser)->value.oper);
		free((*lst_parser));
		(*lst_parser) = NULL;
		(*lst_parser) = temp;
	}
}
