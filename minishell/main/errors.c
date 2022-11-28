/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:20:59 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 13:32:01 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_get_err_code(int err_code, bool is_already_set)
{
	static int	static_err_code = 0;

	if (is_already_set == true)
		static_err_code = err_code;
	return (static_err_code);
}

void	set_err_code(int err_code)
{
	static bool	last_ctrl_c = false;

	if (last_ctrl_c == true)
	{
		last_ctrl_c = false;
		return ;
	}
	if (err_code == ERR_CODE_CTRL_D)
		last_ctrl_c = true;
	_get_err_code(err_code, true);
}

int	get_err_code(void)
{
	return (_get_err_code(0, false));
}
