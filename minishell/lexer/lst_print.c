/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:30 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/16 20:09:31 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_lst(t_list *lst)
{
	while (lst)
	{
		if (lst->type == PIPE)
			printf("{%s}\t[|]\n", lst->content);
		if (lst->type == FILE_IN)
			printf("{%s}\t[<]\n", lst->content);
		if (lst->type == FILE_OUT_OVER)
			printf("{%s}\t[>]\n", lst->content);
		if (lst->type == FILE_OUT_APP)
			printf("{%s}\t[>>]\n", lst->content);
		if (lst->type == HERE_DOC)
			printf("{%s}\t[<<]\n", lst->content);
		if (lst->type == CMD)
			printf("{%s}\t[CMD]\n", lst->content);
		if (lst->type == ARG_FILE_IN)
			printf("{%s}\t[ARG_FILE_IN]\n", lst->content);
		if (lst->type == ARG_FILE_OUT_OVER)
			printf("{%s}\t[ARG_FILE_OUT_OVER]\n", lst->content);
		if (lst->type == ARG_FILE_OUT_APP)
			printf("{%s}\t[ARG_FILE_OUT_APP]\n", lst->content);
		if (lst->type == LIMITOR)
			printf("{%s}\t[LIMITOR]\n", lst->content);
		lst = lst->next;
	}
}

void	ft_print_env(t_env *st)
{
	while (st)
	{
		printf("Var:%s\tValue:%s\n", st->var, st->value);
		st = st->next;
	}
}
