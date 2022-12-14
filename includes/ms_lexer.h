/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:51 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 11:43:37 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_LEXER_H
# define MS_LEXER_H

# include "../includes/minishell.h"

/*
 *		lexer/lexer.c
*/

int			ms_lexer(char *str, t_env *st);

/*
 *		lexer/remove_quotes.c
*/

int			ms_remove_quotes(t_mslist **lst);

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
 *		lexer/utils.c
*/

char		*ms_strjoin_2(char *str1, char *str2);
char		*ms_strjoin_c(char *str, char c);
char		*ms_strcpy(char *str);
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

int			ms_lstadd(t_mslist **lst, t_mslist *new);

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

#endif
