/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lst_parser_oper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:40:22 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/12 16:41:13 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_read_file_in_short(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	int	fd;

	lst = lst->next;
	fd = open(lst->value.oper, O_RDONLY);
	if (fd == -1)
		return (ms_close_return(ERR_WRONG_FILE_IN, pip, 1));
	pip[0][0] = fd;
	ms_read_lst_parser_short(lst->next, st, pip);
	return (EXIT_SUCCESS);
}

int	ms_read_file_out_short(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	int	fd;

	lst = lst->next;
	pip[0][0] = pip[1][0];
	pip[0][1] = pip[1][1];
	if (lst->type == ARG_FILE_OUT_OVER)
		fd = open(lst->value.oper, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else
		fd = open(lst->value.oper, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		return (ms_close_return(ERR_WRONG_FILE_OUT, pip, 1));
	pip[1][1] = fd;
	ms_read_lst_parser_short(lst->next, st, pip);
	return (EXIT_SUCCESS);
}

int	ms_read_pipe_short(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	int	pip2[2][2];
	int	fd_pipe;

	if (lst->next && lst->prev)
	{
		fd_pipe = pipe(pip2[1]);
		if (fd_pipe == -1)
			return (ms_close_return(ERR_PIPE, pip, 1));
		pip2[0][0] = pip[1][0];
		pip2[0][1] = pip[1][1];
		if (!lst->next->next && lst->next->type == CMD)
		{
			ms_is_builtin_short(lst->next->value.cmd, st, pip2, CMD_END);
			return (0);
		}
		else if (lst->next->type == CMD)
			ms_is_builtin_short(lst->next->value.cmd, st, pip2, CMD_MIDDLE);
		lst = lst->next;
		ms_read_lst_parser_short(lst->next, st, pip2);
	}
	else
		return (ms_close_return(ERR_PIPE_CMD, pip, 2));
	return (EXIT_SUCCESS);
}

int	ms_here_doc(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	int		fd;
	char	*str;
	char	*str_readline;
	int		pip2[2][2];

	str_readline = NULL;
	str = ft_strdup("");
	pip2[0][0] = pip[1][0];
	pip2[0][1] = pip[1][1];
	fd = pipe(pip2[1]);
	if (fd == -1)
		return (ms_close_return(ERR_PIPE, pip, 1));
	while (1)
	{
		str_readline = readline("> ");
		if (!str_readline)
			write(1, ERR_SIGNAL_HERE_DOC, ft_strlen(ERR_SIGNAL_HERE_DOC));
		if (!str_readline || strcmp(str_readline, lst->value.oper) == 0)
			break ;
		str = ms_strjoin_here_doc(str, str_readline);
		free (str_readline);
	}
	write(pip2[0][1], str, ft_strlen(str));
	ms_read_lst_parser_short(lst->next, st, pip2);
	return (EXIT_SUCCESS);
}
