/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:38 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/12 16:25:55 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief Ending function for ms_routine.
 * @param to_free: the buffer read allocated in ms_routine -> buf
 * @param exit_code: the wanted exit code in return
 * @return Returns the exit code passed in argument.
 * @todo:	Once exit_inbuilt is done, add here an 'if(exit_code == 130)'make
 * 
*/
static int	_exit_routine(void *to_free, int exit_code)
{
	ft_free(to_free);
	printf("exit\n");
	rl_clear_history();
	free_env(get_env());
	free_wd(get_wd());
	return (exit_code);
}

static int	_routine(void)
{
	char	*buf;

	buf = NULL;
	while (true)
	{
		buf = readline(NAME);
		if (buf == NULL)
			return (_exit_routine(buf, ERR_CODE_CTRL_D));
		if (ft_strlen(buf) != 0)
			add_history(buf);
		while (*buf == ' ')
			buf = ft_str_rm_char(buf, 0);
		if (ft_strlen(buf) && ms_main_lexer(buf, get_env()) == EXIT_FAILURE)
			return (_exit_routine(buf, EXIT_FAILURE));
		//ft_free(buf);
	}
	return (_exit_routine(buf, EXIT_FAILURE));
}

int	main(int argc, char **argv, char **envp)
{
	t_env		*ms_env;

	ms_env = NULL;
	global_signals_handler(argc, argv);
	if (ms_create_env(envp, &ms_env) == EXIT_FAILURE)
		return (ft_putmsg_fd(ERR_ENV_MALLOC, STDERR_FILENO, EXIT_FAILURE));
	if (ms_init_wd() == EXIT_FAILURE)
	{
		free_env(ms_env);
		return (ft_putmsg_fd("PROBLEM\n", STDERR_FILENO, EXIT_FAILURE));
	}
	set_env(ms_env);
	set_err_code(EXIT_SUCCESS);
	return (_routine());
}
