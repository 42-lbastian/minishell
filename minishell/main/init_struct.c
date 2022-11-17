/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:54 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/17 14:47:31 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ms_fill_tab_char(t_struct *main)
{
	int	i;

	i = 0;
	if (ft_strlen(VALID_CHAR) != NB_CHAR_VALID)
	{
		printf(ERR_NB_CHAR);
		exit(EXIT_FAILURE);
	}
	while (VALID_CHAR[i])
	{
		main->char_check.char_valid[i] = VALID_CHAR[i];
		i++;
	}
}

void	ms_init_struct(t_struct *main, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	main->lst = NULL;
	main->char_check.error = 0;
	main->char_check.last_double_q = 0;
	main->char_check.last_simple_q = 0;
	ms_fill_tab_char(main);						//ft_strdup(VALID_CHAR)   ??
}
