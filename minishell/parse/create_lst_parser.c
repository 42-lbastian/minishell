/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <lbastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:18:50 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/22 17:10:53 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ms_file_in_out(t_list **lst, t_lst_parser **lst_parser,
	char **cmd, int i)
{
	ms_lst_parse_add_back(lst_parser, ms_lst_parse_new(NULL, (*lst)->content,
			(*lst)->type));
	(*lst) = (*lst)->next;
	if ((*lst) && (*lst)->type < PIPE)
	{
		ms_lst_parse_add_back(lst_parser, ms_lst_parse_new(NULL,
				(*lst)->content, (*lst)->type));
		(*lst) = (*lst)->next;
		if (cmd)
		{
			while ((*lst) && (*lst)->type == CMD)
			{
				cmd[i] = ft_strdup((*lst)->content);
				(*lst) = (*lst)->next;
				i++;
			}
			ms_lst_parse_add_back(lst_parser, ms_lst_parse_new(cmd, NULL, CMD));
			return (1);
		}
		return (0);
	}
	else
		return (ft_putmsg_fd(ERR_FILE_IN_OUT_ARG, STDERR_FILENO, 2));
}

static int	ft_create_cmd(int *i, t_list **lst, char ***cmd)
{
	
	(*i) = 0;
	(*cmd) = malloc(sizeof(char *) * (ms_count_nb_cmd((*lst)) + 1));
	if (!(*cmd))
		return (1);
	(*cmd)[ms_count_nb_cmd(*lst)] = NULL;
	while((*lst) && (*lst)->type == CMD)
	{
		(*cmd)[(*i)] = ft_strdup((*lst)->content);
		(*i)++;
		(*lst) = (*lst)->next;
	}
	return (0);
}

int	ft_create_lst_parser_main(t_list *lst, t_lst_parser **lst_parser)
{
	char	**cmd;
	int		i;
	int		ret;

	cmd = NULL;
	while (lst)
	{
		if (lst && lst->type == CMD)
			if (ft_create_cmd(&i, &lst, &cmd))
				return (ft_putmsg_fd(ERR_CMD_MALLOC, STDERR_FILENO, 1));
		if (lst && ms_is_type_in_out(lst->type))
		{
			ret = ms_file_in_out(&lst, lst_parser, cmd, i);
			if (ret == 2)
				return (ms_free_cmd(&cmd));
			else if (ret == 1)
				ms_free_cmd(&cmd);

		}
		else if (lst && lst->type == PIPE && !cmd)
		{
			if (ms_lst_parse_add_back(lst_parser, ms_lst_parse_new(NULL, lst->content, lst->type)))
				return (1);
			lst = lst->next;
		}
		if (cmd)
		{
			if (ms_lst_parse_add_back(lst_parser, ms_lst_parse_new(cmd, NULL, CMD)))
				return (ms_free_cmd(&cmd));
			ms_free_cmd(&cmd);
		}
	}
	return (0);
}
