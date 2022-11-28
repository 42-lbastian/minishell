/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:38 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/28 13:32:01 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * @brief Ending function for ms_routine.
 * @param to_free: the buffer read allocated in ms_routine -> str_read
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
	return (exit_code);
}

static int	_routine(void)
{
	char	*str_read;

	str_read = NULL;
	while (true)
	{
		str_read = readline(NAME);
		if (str_read == NULL)
			return (_exit_routine(str_read, ERR_CODE_CTRL_D));
		if (ft_strcmp(str_read, "exit") == 0)
			return (_exit_routine(str_read, get_err_code()));
		if (ft_strlen(str_read) != 0)
			add_history(str_read);
		while (*str_read == ' ')
			str_read = ft_str_rm_char(str_read, 0);
		if (ms_main_lexer(str_read, get_env()) == EXIT_FAILURE)
			return (_exit_routine(str_read, EXIT_FAILURE));
		ft_free(str_read);
	}
	return (_exit_routine(str_read, EXIT_FAILURE));
}

int	main(int argc, char **argv, char **envp)
{
	t_env		*ms_env;

	ms_env = NULL;
	global_signals_handler(argc, argv);
	if (ms_create_env(envp, &ms_env) == EXIT_FAILURE)
		return (ft_putmsg_fd(ERR_ENV_MALLOC, STDERR_FILENO, EXIT_FAILURE));
	set_env(ms_env);
	return (_routine());
}
