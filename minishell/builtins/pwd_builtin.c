/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:52:13 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 16:43:39 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief The pwd builtin mandatory in the project
 * @return Returns EXIT_SUCCESS or EXIT_FAILURE.
*/
int	pwd_builtin(void)
{
	char	*result;

	result = NULL;
	result = getcwd(result, 0);
	if (result == NULL)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	printf("%s\n", result);
	ft_free(result);
	return (EXIT_SUCCESS);
}
