/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:18:50 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/29 14:45:33 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ms_file_in_out(t_mslist **lst, t_lst_parser **lst_parser,
	char ***cmd, int i)
{
	ms_lst_p_addback(lst_parser, ms_lst_parse_new(NULL, (*lst)->content,
			(*lst)->type));
	(*lst) = (*lst)->next;
	if ((*lst) && (*lst)->type < PIPE)
	{
		ms_lst_p_addback(lst_parser, ms_lst_parse_new(NULL,
				(*lst)->content, (*lst)->type));
		(*lst) = (*lst)->next;
		if ((*cmd))
		{
			while ((*lst) && (*lst)->type == CMD)
			{
				(*cmd)[i] = ft_strdup((*lst)->content);
				if (!(*cmd)[i])
					return (ms_free_cmd(cmd));
				(*lst) = (*lst)->next;
				i++;
			}
			ms_lst_p_addback(lst_parser, ms_lst_parse_new((*cmd), NULL, CMD));
			return (ms_free_cmd(cmd));
		}
		return (0);
	}
	else
		return (ft_putmsg_fd(ERR_FILE_IN_OUT_ARG, STDERR_FILENO, 2));
}

static int	ms_create_cmd(int *i, t_mslist **lst, char ***cmd)
{	
	(*i) = 0;
	(*cmd) = malloc(sizeof(char *) * (ms_count_nb_cmd((*lst)) + 1));
	if (!(*cmd))
		return (1);
	(*cmd)[ms_count_nb_cmd(*lst)] = NULL;
	while ((*lst) && (*lst)->type == CMD)
	{
		(*cmd)[(*i)] = ft_strdup((*lst)->content);
		if (!(*cmd)[(*i)])
			return (1);
		(*i)++;
		(*lst) = (*lst)->next;
	}
	return (0);
}

static int	ms_add_pipe(t_mslist **lst, t_lst_parser **lst_parser, char **cmd)
{
	if (ms_lst_p_addback(lst_parser, ms_lst_parse_new(NULL,
				(*lst)->content, (*lst)->type)))
		return (ms_free_cmd(&cmd));
	(*lst) = (*lst)->next;
	return (0);
}

static int	ms_add_cmd(t_lst_parser **lst_parser, char ***cmd)
{
	if ((*cmd))
	{
		if (ms_lst_p_addback(lst_parser, ms_lst_parse_new((*cmd), NULL, CMD)))
			return (ms_free_cmd(cmd));
		ms_free_cmd(cmd);
	}
	return (0);
}

int	ms_create_lst_parser_main(t_mslist *lst, t_lst_parser **lst_parser)
{
	char	**cmd;
	int		i;

	cmd = NULL;
	while (lst)
	{
		if (lst && lst->type == CMD)
		{
			if (ms_create_cmd(&i, &lst, &cmd))
				return (ft_putmsg_fd(ERR_CMD_MALLOC, STDERR_FILENO, 1));
		}
		if (lst && ms_is_type_in_out(lst->type))
		{
			if (ms_file_in_out(&lst, lst_parser, &cmd, i) == 2)
				return (ms_free_cmd(&cmd));
		}
		else if (lst && lst->type == PIPE && !cmd)
			if (ms_add_pipe(&lst, lst_parser, cmd))
				return (1);
		if (ms_add_cmd(lst_parser, &cmd))
			return (1);
	}
	return (0);
}
