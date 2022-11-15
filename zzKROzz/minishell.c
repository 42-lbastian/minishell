/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:16:51 by stelie            #+#    #+#             */
/*   Updated: 2022/11/15 14:38:14 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*line;

	(void)ac;
	(void)av;
	(void)envp;
	line = NULL;
	while (true)
	{
		handle_signals();
		line = readline("minishell > ");
		if (line)
			printf("%s\n", line);
	}
	return (EXIT_SUCCESS);
}
