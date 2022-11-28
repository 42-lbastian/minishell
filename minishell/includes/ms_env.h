/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:23:41 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 16:43:39 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ENV_H
# define MS_ENV_H

# include "../includes/minishell.h"

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
char	*get_env_value(t_env *env, char *var);

/*
 *		main/env_create.c
*/

int		ms_create_env(char **envp, t_env **st);
t_env	*ms_lst_new_env(char *var, char *value);
int		ms_lst_add_back_env(t_env **st, t_env *new);

#endif