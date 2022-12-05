/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:56:13 by stelie            #+#    #+#             */
/*   Updated: 2022/12/05 16:49:49 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief Prints the error for the wrong export arguments, 
 * according to original bash behavior.
*/
static bool	_print_export_error(char *arg)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(ERR_EXPORT, STDERR_FILENO);
	return (false);
}

/*
 * @brief Verifies if an arg is conform to export.
 * @return Returns true if arg can be used, false if not.
*/
bool	_check_export_arg(char	*arg)
{
	int	i;

	if (ft_strlen(arg) == 0)
		return (_print_export_error(NULL));
	i = 1;
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (_print_export_error(arg));
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (_print_export_error(arg));
		i++;
	}
	return (true);
}
