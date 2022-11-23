/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:38 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/23 11:40:21 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	return (exit_code);
}

static int	ms_routine(t_env *ms_env)
{
	char	*str_read;

	str_read = NULL;
	while (true)
	{
		str_read = readline(NAME);
		if (!str_read)
			return (_exit_routine(str_read, 130));
		if (ft_strcmp(str_read, "exit") == 0) // /!\ Temporary : remplacer par le builtin exit dans _exit_routine
			return (_exit_routine(str_read, EXIT_SUCCESS));
		if (ft_strlen(str_read) != 0)
			add_history(str_read);
		if (ms_main_lexer(str_read, ms_env) == EXIT_FAILURE)
			return (_exit_routine(str_read, EXIT_FAILURE));
		free(str_read);
	}
	return (_exit_routine(str_read, EXIT_SUCCESS));
}

/*
 *@todo: free 'env_t *st'
 */
int	main(int argc, char **argv, char **envp)
{
	t_env		*ms_env;

	ms_env = NULL;
	global_signals_handler(argc, argv);
	if (ms_create_env(envp, &ms_env) == EXIT_FAILURE)
		return (ft_putmsg_fd(ERR_ENV_MALLOC, STDERR_FILENO, EXIT_FAILURE));
	return (ms_routine(ms_env));
}
