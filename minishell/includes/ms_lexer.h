/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:51 by stelie            #+#    #+#             */
/*   Updated: 2022/12/12 18:04:43 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_LEXER_H
# define MS_LEXER_H

# include "../includes/minishell.h"

/*
 *		lexer/lexer.c
*/

int			ms_main_lexer(char *str, t_env *st);

/*
 *		lexer/remove_quotes.c
*/

int			ms_main_remove_quotes(t_mslist **lst);

/*
 *		lexer/expand_env_var.c
*/
int			ms_main_replace_env(t_mslist **lst, t_env *st);

/*
 *		lexer/expand_env_var_2.c
*/
int			ms_split_expand(char *temp, t_mslist **lst, char **split);
int			ms_error_return(char *str);

/*
 *		lexer/count.c
*/

int			ms_start_read_var(char *str, int index);
int			ms_lenght_read_var(char *str, int index);
int			ms_count_char(char *str);
int			ms_count_nb_quotes(char *str);
int			ms_count_remove_quotes(char *str);

/*
 *		lexer/utils.c
*/

int			ms_strjoin_3(char *dest, char *str, int start);
char		*ms_strjoin_2(char *str1, char *str2);
char		*ms_strjoin_c(char *str, char c);
int			ms_have_space(char *str);

/*
 *		lexer/utils_2.c
*/

char		*ms_strcpy_2(char *str);
int			ms_strlen(const char *str);

/*
 *		lexer/read_char.c
*/

void		ms_read_special(char *str, t_struct *main);
void		ms_read_cmd(char *str, t_struct *main);
int			ms_count_read_quotes(char *str, int start);

/*
 *		lexer/unwanted.c
*/

char		*ms_check_quotes(char *str, t_struct *main);
char		*ms_remove_special(char *str, int i);

/*
 *		lexer/lst.c
*/

int			ms_lst_size(t_mslist *lst);
char		*ms_get_lst_str_index(t_mslist *lst, int index);
int			ms_lstadd(t_mslist **lst, t_mslist *new);
char		*ms_find_var(char *str, t_env *st);

/*
 *		lexer/lst_2.c
*/

t_mslist	*ms_lst_new_join(char *content, int type);
t_mslist	*ms_lst_new(char *content, int type);
t_mslist	*ms_lst_last(t_mslist *lst);
int			ms_lstadd_back(t_mslist **lst, t_mslist *new);

/*
 *		lexer/remove_spaces.c
*/

int			ms_remove_spaces(t_mslist **lst);

/*
 *		lexer/set_type_cmd.c
*/

int			ms_set_type_cmd(t_mslist **lst);

#endif
