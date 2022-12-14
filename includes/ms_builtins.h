/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:46:17 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 14:29:28 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

# include "../includes/minishell.h"
# include <dirent.h>

# define ERR_CD_ARGS "too many arguments\n"
# define ERR_HOME_NOT_SET "HOME not set\n"

# define ERR_ENV_OPTION ": env builtin with args not implemented\n"
# define ERR_ENV_PERM ": Premission denied\n"
# define ERR_NO_SUCH ": No such file or directory\n"

# define ERR_EXIT_VALID ": numeric argument required\n"
# define ERR_EXIT_ARGS "exit: too many arguments\n"

# define ERR_EXPORT "\': not a valid identifier\n"
# define EXIT_MSG "exit\n"

/*
 * BUILTINS
*/

int	echo_builtin(char **args);
int	cd_builtin(char **args);
int	pwd_builtin(void);
int	export_builtin(char **args);
int	unset_builtin(char **args);
int	env_builtin(char **args);
int	exit_builtin(char **args);

/*
 * UTILS
*/

int	_export_no_args(t_env *env);

#endif
