/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_parse_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:09:28 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/28 16:43:39 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_print_lst_parse(t_lst_parser *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		if (lst->type == CMD)
		{
			while (lst->value.cmd[i])
			{
				printf("%s-[%d]\t", lst->value.cmd[i], lst->type);
				i++;
			}
			printf("\n");
		}
		else
			printf("%s-[%d]\n", lst->value.oper, lst->type);
		lst = lst->next;
	}
}

void	ms_print_lst_parse_reverse(t_lst_parser *lst)
{
	int	i;

	lst = ms_lst_parse_last(lst);
	while (lst)
	{
		i = 0;
		if (lst->type == CMD)
		{
			while (lst->value.cmd[i])
			{
				printf("%s\t", lst->value.cmd[i]);
				i++;
			}
			printf("\n");
		}
		else
			printf("%s\n", lst->value.oper);
		lst = lst->prev;
	}
}
