/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:31:13 by stelie            #+#    #+#             */
/*   Updated: 2022/12/02 13:30:02 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static bool	_is_valid_exit_flag(char *arg)
{
	int		i;
	bool	sign;

	sign = false;
	i = 0;
	while (arg[i])
	{
		if ((arg[i] == '-' || arg[i] == '+') && sign == false)
		{
			sign = true;
			i++;
		}
		if (ft_isdigit(arg[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

/*
 * @brief the exit builtin mandatory in the project
 * @param args: a string array where the first str is "exit"
 * @return Returns the err_code.
*/
int	exit_builtin(char **args)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (ft_strcmp(args[0], "exit") != 0)
		return (EXIT_FAILURE);
	if (args[1])
		exit_code = ft_atoi(args[1]);
	else
		exit_code = get_err_code();
	if (_is_valid_exit_flag(args[1]) == false)
	{
		printf("exit: %s: %s", args[1], ERR_EXIT_VALID);
		exit_code = 2;
	}
	else if (args[1] && args[2])
	{
		ft_putstr_fd("%s", ERR_EXIT_ARGS, STDERR_FILENO);
		return (ft_putmsg_fd("exit\n", STDERR_FILENO, EXIT_FAILURE));
	}
	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit(exit_code);
	return (exit_code);
}
