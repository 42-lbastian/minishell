/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:04:34 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/13 15:25:28 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_parse(t_struct *main_s, t_mslist *lst, t_env *st)
{
	int				ret;
	int				pip[2][2];
	int				fd_pipe;
	t_lst_parser	*lst_parser_dumb;

	lst_parser_dumb = NULL;
	if (ms_create_lst_parser_main(lst, &lst_parser_dumb))
		return (ERR_CODE_INVALID);
	fd_pipe = pipe(pip[1]);
	if (fd_pipe == -1)
		return (ft_putmsg_fd(ERR_PIPE, STDERR_FILENO, EXIT_FAILURE));
	pip[0][0] = -1;
	ret = ms_read_lst_parser_short(lst_parser_dumb, st, pip);
	ms_free_parse(&lst_parser_dumb);
	ms_free_main_s(main_s);
	if (ret == EXIT_FAILURE)
		return (ERR_CODE_INVALID);
	if (ret == -1)
		_exit_routine(NULL, get_err_code());
	return (EXIT_SUCCESS);
}
