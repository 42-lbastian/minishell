/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:38 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/17 16:43:57 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ms_init_struct(t_struct *main, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	main->lst = NULL;
	main->char_check.error = 0;
	main->char_check.last_double_q = 0;
	main->char_check.last_simple_q = 0;
	if (ms_strlen(VALID_CHAR) == NB_CHAR_VALID)
		main->char_check.char_valid = ft_strdup(VALID_CHAR);
	else
		exit (EXIT_FAILURE);     // PAS DE FREE!!
}

int	ms_routine(t_struct *main_s, t_env *st)
{
	char	*str_read;

	str_read = NULL;
	g_glob.ret = 0;
	while (true)
	{
		g_glob.pid = 0;
		g_glob.sigint = 0;
		g_glob.sigquit = 0;
		str_read = readline(NAME);
		if (!str_read)
			return (EXIT_FAILURE);
		if (ft_strcmp(str_read, "exit") == 0)
			break ;	//NEED TO ADD THE EXIT MESSAGE SEQUENCE
		if (ft_strlen(str_read) != 0)	//check if cant use libft strlen
			add_history(str_read);
		if (ft_main_lexer(str_read, main_s, st))
		{
			//EXPLICIT ERROR MSG && NO EXIT OPER ERROR
			ft_putstr_fd(ERR_LEXER, STDERR_FILENO);
			//ft_free_all(&main_s->lst);
			break ;
		}
		ft_parse(main_s->lst, st);
		//ft_print_lst(main_s->lst);
		ft_free_lst(&main_s->lst);
	}
	ft_free_all(&main_s->lst);
	free(str_read);
	return (g_glob.ret);
}

t_sig	g_glob;

int	main(int argc, char **argv, char **envp)
{
	t_struct	*main_s;
	t_env		*st;

	st = NULL;
	global_signals_handler();
	if (ms_create_env(envp, &st))	//MALLOC BUT NOT FREED + ms_clear_env LEAKS ANYWAY
		return (ft_putmsg_fd(ERR_ENV_MALLOC, STDERR_FILENO, EXIT_FAILURE));
	main_s = malloc(sizeof(t_struct));
	if (!main_s)
		return (ft_putmsg_fd(ERR_MAIN_MALLOC, STDERR_FILENO, EXIT_FAILURE));
	ms_init_struct(main_s, argc, argv);
	ms_routine(main_s, st);
	free(main_s);
	clear_history();
	return (EXIT_SUCCESS);
}
