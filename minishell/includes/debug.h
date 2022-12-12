/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:24:03 by stelie            #+#    #+#             */
/*   Updated: 2022/12/07 10:26:07 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "minishell.h"

# define ERR_ENV_MALLOC "Error Malloc env\n"
# define ERR_CHAR_VALID_MALLOC "Error Malloc Char Valid\n"
# define ERR_MAIN_MALLOC "Error Malloc Main struct\n"
# define ERR_LEXER "Error Lexer\n"
# define ERR_NB_CHAR "ERROR NB_CHAR\n"
# define ERR_PIPE "Error Pipe Creation\n"
# define ERR_LST_PARSER_CREATION "Error lst parser Creation\n"
# define ERR_FORK "Error Fork\n"
# define ERR_MALLOC_ENV_ARR "Error Malloc env array\n"

# define TEST "test\n"
# define COUCOU "COUCOU\n"

/*
 *  ------- DEBUG FUNCTIONS ----------
*/

int		_ms_print_env(t_env *ms_env);
void	_ms_print_lst(t_mslist *lst);
int		_basic_checks(void);
void	ms_clear_env(t_env **st);
void	_display_env_pointers(void);

#endif