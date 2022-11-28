/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:52:01 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 16:40:19 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_builtin(char **args)
{
	bool	newline;

	newline = true;
	args++;
	if (*args && ft_strcmp(*args, "-n") == 0)
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
