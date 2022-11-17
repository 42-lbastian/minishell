/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:38 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/17 10:24:14 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_main_action(t_struct *main_s, char *str_read, t_env *st)
{
	g_glob.ret = 0;
	while (1)
	{
		g_glob.pid = 0;
		g_glob.sigint = 0;
		g_glob.sigquit = 0;
		global_signals_handler();
		//str_read = readline(RED NAME NORMAL);
		str_read = readline(NAME);
		if (!str_read)
			return (0);
		if (ft_strcmp_2(str_read, "exit") == 0)
			break ;
		if (ft_strlen(str_read) != 0)
			add_history(str_read);
		if (ft_main_lexer(str_read, main_s, st))
		{
			//EXPLICIT ERROR MSG && NO EXIT OPER ERROR
			ft_putstr_fd("Error Lexer\n", STDERR_FILENO);
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
	char		*str_read;
	t_struct	*main_s;
	t_env		*st;

	st = NULL;
	if (ft_create_env(envp, &st))
	{
		ft_putstr_fd("Error Malloc env\n", STDERR_FILENO);
		return (1);
	}
	main_s = malloc(sizeof(t_struct));
	if (!main_s)
	{
		ft_putstr_fd("Error Malloc Main struct\n", STDERR_FILENO);
		return (1);
	}
	str_read = NULL;
	ft_init_struct(main_s, argc, argv);
	ft_main_action(main_s, str_read, st);
	free(main_s);
	clear_history();
	return (0);
}
