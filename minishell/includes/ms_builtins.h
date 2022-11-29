/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:46:17 by stelie            #+#    #+#             */
/*   Updated: 2022/11/29 15:26:51 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

# include "../includes/minishell.h"
# include <dirent.h>

# define ERR_CD_ARGS "cd: too many arguments\n"
# define ERR_HOME_NOT_SET "cd: HOME not set\n"

/*
 * @brief structure for CD builtin.
*/
typedef struct s_wd
{
	char	*home;
	char	*cwd;
	char	*pwd;
	char	*oldpwd;
}				t_wd;

/*
 * BUILTINS
*/

int		echo_builtin(char **args);
int		cd_builtin(char **args);
int		pwd_builtin(void);
int		exit_builtin(char **args);

#endif
