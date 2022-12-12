/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:23:41 by stelie            #+#    #+#             */
/*   Updated: 2022/12/07 17:54:50 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ENV_H
# define MS_ENV_H

# include "../includes/minishell.h"

# define PWD 0
# define OLDPWD 1
/*
 * @brief Environnement variable structure
 * @param var: (char *) name of the environnement variable
 * @param value: (char *) what the var contains
 * @param next: (t_env *) address to the next t_env variable
*/
typedef struct s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
}				t_env;

/*
 *		main/env_handler.c
*/

void	set_env(t_env *env);
t_env	*get_env(void);
void	free_env(t_env *env);
void	free_one_env(t_env *env);

/*
 *		main/env_create.c
*/

int		ms_create_env(char **envp, t_env **st);
t_env	*ms_new_env(char *var, char *value);
int		ms_add_back_env(t_env **st, t_env *new);

/*
 *		main/env_utils.c
*/

bool	ms_env_var_exists(t_env *env, char *var);
char	*get_env_value(t_env *env, char *var);
t_env	*ms_free_one_env(t_env *env, char *var);
int		ms_env_update(t_env *env, char *var, char *new_value);

/*
 *		main/wd_utils.c
*/

int		ms_init_wd(void);
void	set_wd(char **wd);
char	**get_wd(void);
void	free_wd(char **wd);

#endif