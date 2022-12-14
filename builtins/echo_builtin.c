/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:52:01 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 13:33:16 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static bool	_no_nl(char *str)
{
	if (ft_strncmp(str, "-n", 2) != 0)
		return (false);
	str += 2;
	while (*str && *str == 'n')
		str++;
	if (*str == '\0')
		return (true);
	return (false);
}

/*
 * @brief the exit builtin mandatory in the project
 * @param args: a string array where the first str is "echo"
 * @return Returns the err_code.
*/
int	echo_builtin(char **args)
{
	bool	newline;

	newline = true;
	args++;
	while (*args && _no_nl(*args))
	{
		newline = false;
		args++;
	}
	while (*args)
	{
		printf("%s", *args);
		if (ft_strlen(*args) != 0 && *(args + 1) != NULL)
			printf(" ");
		args++;
	}
	if (newline)
		printf("\n");
	return (EXIT_SUCCESS);
}
