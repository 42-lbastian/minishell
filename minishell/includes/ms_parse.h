/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:35:31 by stelie            #+#    #+#             */
/*   Updated: 2022/11/29 13:40:51 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSE_H
# define MS_PARSE_H

#include "../includes/minishell.h"

/*
 * @brief t_lst_parser - double way list of Commands
 * @param next: s_lst_cmd *
 * @param prev: s_lst_cmd *
 * @param value: t_value
 * @param type: int
*/
typedef struct s_lst_cmd
{
	struct s_lst_cmd	*next;
	struct s_lst_cmd	*prev;
	t_value				value;
	int					type;

}				t_lst_parser;

/*
**		parse/parse.c
*/

int		ms_parse(t_struct *main_s, t_mslist *lst, t_env *st);

/*
**		parse/create_lst_parser.c
*/
int		ms_create_lst_parser_main(t_mslist *lst, t_lst_parser **lst_parser);

/*
**		parse/read_lst_parser_short.c
*/
int		ms_read_lst_parser_short(t_lst_parser *lst, t_env *st, int pip[2][2]);

/*
**		parse/read_lst_parser_utils.c
*/
int		ms_close_return(char *msg, int pip[2][2]);

/*
**		parse/create_lst_parser_utils.c
*/

int		ms_count_nb_cmd(t_mslist *lst);
int		ms_free_cmd(char ***cmd);
int		ms_is_type_in_out(int type);

/*
**		parse/exec.c
*/
int		ms_is_builtin_short(char **complete_cmd, t_env *st, int pipe[2][2], int type);

/*
**		parse/exec_dup_fd.c
*/
void	ms_set_dup2(int pip[2][2], int type);
void	ms_close_fd_fork(int pip[2][2], int type);
void	ms_close_fd_parent(int pip[2][2], int type);

/*
**		parse/exec_path.c
*/
char	*ms_find_path(char *cmd, char **all_path);
char	**ms_env_array(t_env *st);

/*
**		parse/exec_path_utils.c
*/
int		ms_env_size(t_env *st);
char	*ms_strjoin_env(char *str1, char *str2, char c, int i);

/*
**		parse/exec_path_free.c
*/
void	ms_free_split(char **all_path);
char	**ms_free_env_arr(char **env_arr);

/*
**		parse/lst_parse.c
*/

t_lst_parser	*ms_lst_parse_new(char **cmd, char *oper, int type);
int		ms_lst_p_addback(t_lst_parser **lst, t_lst_parser *new);
int		ms_lst_parse_add_front(t_lst_parser **lst, t_lst_parser *new);
char	*ms_find_var_path(char *str, t_env *st);
t_lst_parser	*ms_lst_parse_last(t_lst_parser *lst);

/**
**		parse/lst_parse_print.c
**/

void	ms_print_lst_parse(t_lst_parser *lst);
void	ms_print_lst_parse_reverse(t_lst_parser *lst);

/*
**		parse/tools.c
*/

char	**ms_strcpy_cmd(char **arr);

#endif
