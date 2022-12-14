/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:37:09 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 11:47:28 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RED "\1\033[1;31m\2"
# define NORMAL "\1\x1b[0m\2"
# define NAME "minishell> "

# define VALID_CHAR "=/|<>.'\" $?-_~+"
# define CMD_CHAR " ><|"
# define C_CHECK_CHAR "\'\"$ "
# define SPECIAL_CHAR "|<>"
# define ERR_CODE_CTRL_D 130
# define ERR_CODE_INVALID 2

# define SIMPLE 0
# define DOUBLE 1

# define DEFAULT 1
# define CMD 2
# define ARG_FILE_IN 3
# define ARG_FILE_OUT_OVER 4
# define ARG_FILE_OUT_APP 5
# define LIMITOR 6
# define PIPE 7 /* | */
# define FILE_IN 8 /* < */
# define FILE_OUT_OVER 9 /* > */
# define FILE_OUT_APP 10 /* >> */
# define HERE_DOC 11 /* << */

# define CMD_BEGIN 0
# define CMD_END 1
# define CMD_MIDDLE 2
# define CMD_FILE_IN 3
# define CMD_FILE_IN_END 4
# define CMD_FILE_OUT 5
# define CMD_FILE_OUT_END 6
# define CMD_HERE_DOC 7
# define CMD_HERE_DOC_END 8
# define CMD_ALONE 9

# define CD 0
# define ECHO 1

# define ERR_ENV_MALLOC "Error Malloc env\n"
# define ERR_CHAR_VALID_MALLOC "Error Malloc Char Valid\n"
# define ERR_MAIN_MALLOC "Error Malloc Main struct\n"
# define ERR_PIPE "Error Pipe Creation\n"
# define ERR_FILE_IN_OUT_ARG "bash: syntax error near unexpected token\n"
# define ERR_CMD_MALLOC "Error Malloc cmd parser\n"
# define ERR_WRONG_FILE_IN "bash: No such file or directory\n"
# define ERR_WRONG_FILE_OUT "Wrong file or access denied\n"
# define ERR_PIPE_CMD "bash: syntax error near unexpected token `|'\n"
# define ERR_FORK "Error Fork\n"
# define ERR_PATH "Command not found/access denied\n"
# define ERR_MALLOC_ENV_ARR "Error Malloc env array\n"
# define ERR_SIGNAL_HD "bash: warning: here-document delimited by end-of-file\n"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/includes/libft.h"
# include "ms_structures.h"
# include "ms_env.h"
# include "ms_lexer.h"
# include "ms_parse.h"
# include "ms_builtins.h"
# include <errno.h>

/*
 *		main/signal.c
*/

void	signal_handler(int argc, char **argv);

/*
*		main/errors.c
*/

int		get_err_code(void);
void	set_err_code(int err_code);

/*
 *		main/free.c
*/

void	ms_free_main_s(t_struct *main_s);
void	ms_free_parse(t_lst_parser **lst_parser);

/*
 *		main/minishell.c
*/
int		_exit_routine(void *to_free, int exit_code);

#endif
