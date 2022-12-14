/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lst_parser_oper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:40:22 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 12:59:57 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	_close_return(char *msg, int pip[2][2], int err)
{
	set_err_code(err);
	close(pip[1][0]);
	close(pip[1][1]);
	return (ft_putmsg_fd(msg, STDERR_FILENO, EXIT_FAILURE));
}

int	ms_read_file_in(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	int	fd;

	lst = lst->next;
	fd = open(lst->value.oper, O_RDONLY);
	if (fd == -1)
		return (_close_return(ERR_WRONG_FILE_IN, pip, 1));
	pip[0][0] = fd;
	return (ms_read_lst_parser(lst->next, st, pip));
}

int	ms_read_file_out(t_lst_parser *lst, t_env *st, int pip[2][2])
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
		return (_close_return(ERR_WRONG_FILE_OUT, pip, 1));
	pip[1][1] = fd;
	return (ms_read_lst_parser(lst->next, st, pip));
}

int	ms_read_pipe(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	int	pip2[2][2];
	int	fd_pipe;

	if (lst->next && lst->prev)
	{
		fd_pipe = pipe(pip2[1]);
		if (fd_pipe == -1)
			return (_close_return(ERR_PIPE, pip, 1));
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
		ms_read_lst_parser(lst->next, st, pip2);
	}
	else
		return (_close_return(ERR_PIPE_CMD, pip, 2));
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
		return (_close_return(ERR_PIPE, pip, 1));
	while (1)
	{
		str_readline = readline("> ");
		if (!str_readline)
			write(1, ERR_SIGNAL_HD, ft_strlen(ERR_SIGNAL_HD));
		if (!str_readline || strcmp(str_readline, lst->value.oper) == 0)
			break ;
		str = ms_strjoin_here_doc(str, str_readline);
		free (str_readline);
	}
	write(pip2[0][1], str, ft_strlen(str));
	ms_read_lst_parser(lst->next, st, pip2);
	return (EXIT_SUCCESS);
}
