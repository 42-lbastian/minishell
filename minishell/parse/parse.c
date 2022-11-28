#include "../includes/minishell.h"

int		ms_parse(t_mslist *lst, t_env *st)
{
	int				pip[2][2];
	int				fd_pipe;
	t_lst_parser	*lst_parser_dumb;

	lst_parser_dumb = NULL;
	if (ms_create_lst_parser_main(lst, &lst_parser_dumb))
		return (ft_putmsg_fd(ERR_LST_PARSER_CREATION, STDERR_FILENO,
			ERR_CODE_INVALID));
	fd_pipe = pipe(pip[1]);
	if (fd_pipe == -1)
		return (ft_putmsg_fd(ERR_PIPE, STDERR_FILENO, EXIT_FAILURE));
	//if (ms_read_lst_parser(lst_parser_dumb, st, pip[0], pip[1], 0))
	//	return (ERR_CODE_INVALID);
	if (ms_read_lst_parser_short(lst_parser_dumb, st, pip, 0))
		return (ERR_CODE_INVALID);
	ms_free_parse(&lst_parser_dumb);
	return (EXIT_SUCCESS);
}
