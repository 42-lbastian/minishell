/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:31:13 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 13:09:35 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief Tests if the given string is over the limits of LLONG_MIN / LLONG_MAX
*/
static bool	_compare_limits(long long nb, char *str)
{
	int	i;
	int	mod;

	i = ft_strlen(str);
	while (--i)
	{
		if (str[i] == '-' && nb == 0)
			return (true);
		mod = nb % 10;
		if (mod < 0)
			mod *= -1;
		if (str[i] != ('0' + mod))
			return (false);
		nb = nb / 10;
	}
	return (true);
}

/*
 * @brief Displays the adequate error msg if exit is not used correctly.
*/
static int	_display_exit_error(char *arg, char *error, int exit_code)
{
	ft_putstr_fd(EXIT_MSG, STDERR_FILENO);
	if (ft_strcmp(error, ERR_EXIT_ARGS) == 0)
		ft_putstr_fd(error, STDERR_FILENO);
	else
	{
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(error, STDERR_FILENO);
	}
	return (exit_code);
}

/*
 * @brief Checks if the given exit flag is valid.
*/
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
	if (args && args[1] == NULL)
	{
		printf(EXIT_MSG);
		set_err_code(exit_code);
		return (-1);
	}
	else if (args && args[2] != NULL)
		return (_display_exit_error(args[1], ERR_EXIT_ARGS, EXIT_FAILURE));
	else if (args && _is_valid_exit_flag(args[1]) == false)
		exit_code = _display_exit_error(args[1], ERR_EXIT_VALID, 2);
	else
	{
		exit_code = ft_atoll(args[1]);
		if (_compare_limits(ft_atoll(args[1]), args[1]) == false)
		exit_code = _display_exit_error(args[1], ERR_EXIT_VALID, 2);
	}
	set_err_code(exit_code);
	return (-1);
}
