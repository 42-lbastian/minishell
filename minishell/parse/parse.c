#include "../include/minishell.h"

int		ms_print_cmd(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		printf("%s ", str[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int	ms_read_dumb(t_lst_parser *lst, t_env *st, int read, int write, int fd2)
{
	int	pip[2];
	int	fd;

	if (lst && lst->prev == NULL && lst->next == NULL && lst->type == CMD)
	{
		pipe(pip);
		ms_is_builtin_dumb(lst->value.cmd, st, read, write, pip[0], pip[1], CMD_END);
	}
	else if (lst && lst->type == CMD && fd2 == 0)
	{
		ms_is_builtin_dumb(lst->value.cmd, st, 0, 1, read, write, CMD_BEGIN);
		lst = lst->next;
	}
	else if (lst && lst->prev && lst->prev->type == ARG_FILE_IN && lst->type == CMD)
	{
		if (!lst->next)
			ms_is_builtin_dumb(lst->value.cmd, st, fd2, 1, read, write, CMD_FILE_IN_END);
		else
			ms_is_builtin_dumb(lst->value.cmd, st, fd2, 1, read, write, CMD_FILE_IN);
		lst = lst->next;
	}
	else if (lst && lst->prev && lst->type == CMD && (lst->prev->type == ARG_FILE_OUT_OVER || lst->prev->type == ARG_FILE_OUT_APP))
	{
		if (!lst->next)
			ms_is_builtin_dumb(lst->value.cmd, st, read, 1, write, fd2, CMD_FILE_OUT_END);
		else
			ms_is_builtin_dumb(lst->value.cmd, st, read, 1, write, fd2, CMD_FILE_OUT);
		lst = lst->next;
	}
	else if (lst && lst->next && lst->type == CMD)
		lst = lst->next;
	if (lst && lst->type == PIPE)
	{
		if (lst->next && lst->prev)
		{
			pipe(pip);
			if (!lst->next->next && lst->next->type == CMD)
			{
				ms_is_builtin_dumb(lst->next->value.cmd, st, read, write, pip[0], pip[1], CMD_END);
				return (0);
			}
			else if (lst->next->type == CMD)
				ms_is_builtin_dumb(lst->next->value.cmd, st, read, write, pip[0], pip[1], CMD_MIDDLE);
			lst = lst->next;
			ms_read_dumb(lst->next, st, pip[0], pip[1], 1);
		}
		else
		{
			ft_putstr_fd("bash: syntax error near unexpected token `|'\n", STDERR_FILENO);
			return (1);
		}
	}
	if (lst && lst->type == FILE_IN)
	{
		//if (lst->next && lst->next->type == ARG_FILE_IN)
		//{

			pipe(pip);
			lst = lst->next;
			fd = open(lst->value.oper, O_RDONLY);
			close(read);
			close(write);
			if (fd == -1)
			{
				close(pip[0]);
				close(pip[1]);
				ft_putstr_fd("bash: No such file or directory\n", STDERR_FILENO);
				return (1);
			}
			ms_read_dumb(lst->next, st, pip[0], pip[1], fd);

		//}
		//else
		//{
		//	ft_putstr_fd("bash: syntax error near unexpected token HELLO\n", STDERR_FILENO);
		//	return (1);
		//}	
	}
	if (lst && (lst->type == FILE_OUT_OVER || lst->type == FILE_OUT_APP))
	{
		lst = lst->next;
		if (lst->type == ARG_FILE_OUT_OVER)
			fd = open(lst->value.oper, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else
			fd = open(lst->value.oper, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (fd == -1)
		{
			close(read);
			close(write);
			ft_putstr_fd("bash: No such file or directory\n", STDERR_FILENO);
			return (1);
		}
		ms_read_dumb(lst->next, st, read, write, fd);
	}
	return (0);
}

int		ms_parse(t_list *lst, t_env *st)
{
	int pip[2];
	int	fd_pipe;

	t_lst_parser *lst_parser_dumb;
	lst_parser_dumb = NULL;
	if (ft_create_lst_parser_main(lst, &lst_parser_dumb))
		return (ft_putmsg_fd(ERR_LST_PARSER_CREATION, STDERR_FILENO,
			EXIT_FAILURE));
	fd_pipe = pipe(pip);
	if (fd_pipe == -1)
		return (ft_putmsg_fd(ERR_PIPE, STDERR_FILENO, EXIT_FAILURE));
	if (ms_read_dumb(lst_parser_dumb, st, pip[0], pip[1], 0))
		return (1);
	ms_free_parse(&lst_parser_dumb);
	return (EXIT_SUCCESS);
}
