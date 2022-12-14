/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:18:50 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 11:58:22 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	_file_io(t_mslist **lst, t_lst_parser **lst_p, char ***cmd, int i)
{
	ms_lst_p_addback(lst_p, ms_lst_parse_new(NULL, (*lst)->content,
			(*lst)->type));
	(*lst) = (*lst)->next;
	if ((*lst) && (*lst)->type < PIPE)
	{
		ms_lst_p_addback(lst_p, ms_lst_parse_new(NULL,
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
			ms_lst_p_addback(lst_p, ms_lst_parse_new((*cmd), NULL, CMD));
			return (ms_free_cmd(cmd));
		}
		return (0);
	}
	else
		return (ms_set_err_int_out(ERR_FILE_IN_OUT_ARG, STDERR_FILENO));
}

static int	_create_cmd(int *i, t_mslist **lst, char ***cmd)
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

static int	_add_pipe(t_mslist **lst, t_lst_parser **lst_parser, char **cmd)
{
	if (ms_lst_p_addback(lst_parser, ms_lst_parse_new(NULL,
				(*lst)->content, (*lst)->type)))
		return (ms_free_cmd(&cmd));
	(*lst) = (*lst)->next;
	return (0);
}

static int	_add_cmd(t_lst_parser **lst_parser, char ***cmd)
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
			if (_create_cmd(&i, &lst, &cmd))
				return (ft_putmsg_fd(ERR_CMD_MALLOC, STDERR_FILENO, 1));
		}
		if (lst && ms_is_type_in_out(lst->type))
		{
			if (_file_io(&lst, lst_parser, &cmd, i) == 2)
				return (ms_free_cmd(&cmd));
		}
		else if (lst && lst->type == PIPE && !cmd)
			if (_add_pipe(&lst, lst_parser, cmd))
				return (1);
		if (_add_cmd(lst_parser, &cmd))
			return (1);
	}
	return (0);
}
