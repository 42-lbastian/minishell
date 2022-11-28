/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:46:17 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 16:43:39 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

# include "../includes/minishell.h"

/*
 * BUILTINS
*/

int		echo_builtin(char **args);
int		cd_builtin(char **args);
int		pwd_builtin(void);
int		exit_builtin(char **args);

#endif
