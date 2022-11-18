/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:38 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/18 18:34:51 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
 * @name: _basic_check()
 * @brief sert a verifier les constantes, defines etc.. (A supprimer plus tard)
 * @return Retourne EXIT_SUCCESS ou EXIT_FAILURE.
*/
static int	_basic_checks(void)
{
	if (ms_strlen(VALID_CHAR) != NB_CHAR_VALID)
		return (ft_putmsg_fd(ERR_NB_CHAR, STDERR_FILENO, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

/*
 * @todo Verifier si le FT_STRDUP a bien reussi et free main le cas echeant
*/
void	ms_init_struct(t_struct *main, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	main->lst = NULL;
	main->char_check.error = 0;
	main->char_check.last_double_q = 0;
	main->char_check.last_simple_q = 0;
	main->char_check.char_valid = ft_strdup(VALID_CHAR);  //NEED CHECK IF FT_STRDUP FAILED
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
		if (ms_main_lexer(str_read, main_s, st))
		{
			//EXPLICIT ERROR MSG && NO EXIT OPER ERROR
			ft_putstr_fd(ERR_LEXER, STDERR_FILENO);
			//ms_free_all(&main_s->lst);
			break ;
		}
		ms_parse(main_s->lst, st);
		//ms_print_lst(main_s->lst);
		ms_free_lst(&main_s->lst);
		free(str_read);
	}
	free(str_read);
	return (g_glob.ret);
}

t_sig	g_glob;

/*
 *@todo: free 'env_t *st'
 */
int	main(int argc, char **argv, char **envp)
{
	t_struct	*main_s;
	t_env		*st;

	_basic_checks();
	st = NULL;
	global_signals_handler();
	if (ms_create_env(envp, &st))
		return (ft_putmsg_fd(ERR_ENV_MALLOC, STDERR_FILENO, EXIT_FAILURE));
	main_s = malloc(sizeof(t_struct));
	if (!main_s)
	{
		ms_clear_env(&st);
		return (ft_putmsg_fd(ERR_MAIN_MALLOC, STDERR_FILENO, EXIT_FAILURE));
	}
	ms_init_struct(main_s, argc, argv);
	if (!main_s->char_check.char_valid)
	{
		ms_free_all(main_s, &st);
		return (ft_putmsg_fd(ERR_MAIN_MALLOC, STDERR_FILENO, EXIT_FAILURE));
	}
	ms_routine(main_s, st);
	ms_free_all(main_s, &st);
	clear_history();
	return (EXIT_SUCCESS);
}
