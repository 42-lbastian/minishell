/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:46:17 by stelie            #+#    #+#             */
/*   Updated: 2022/12/05 17:26:15 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

# include "../includes/minishell.h"
# include <dirent.h>

# define ERR_CD_ARGS "cd: too many arguments\n"
# define ERR_HOME_NOT_SET "cd: HOME not set\n"
# define ERR_ENV_PERM ": Premission denied\n"
# define ERR_ENV_NO_SUCH ": No such file or directory\n"
# define ERR_EXIT_VALID ": numeric argument required\n"
# define ERR_EXIT_ARGS "exit : too many arguments\n"
# define ERR_EXPORT "\': not a valid identifier\n"
# define EXIT_MSG "exit\n"

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
int		export_builtin(char **args);
int		unset_builtin(char **args);
int		env_builtin(char **args);
int		exit_builtin(char **args);

/*
 * BUILTIN UTILS
*/

bool	_check_export_arg(char	*arg);

#endif
