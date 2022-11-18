#ifndef MINISHELL_H
# define MINISHELL_H

# define RED "\1\033[1;31m\2"
# define NORMAL "\1\x1b[0m\2"
# define NAME "minishell> "

# define NB_CHAR_VALID 13
# define VALID_CHAR "=/|<>.'\" $?-_"
# define CMD_CHAR " ><|"
# define C_CHECK_CHAR "\'\"$ "
# define SPECIAL_CHAR "|<>"

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

# define CD 0
# define ECHO 1

# define ERR_ENV_MALLOC "Error Malloc env\n"
# define ERR_MAIN_MALLOC "Error Malloc Main struct\n"
# define ERR_LEXER "Error Lexer\n"
# define ERR_NB_CHAR "ERROR NB_CHAR\n"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

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

//Value for AST/LST_CMD
typedef union s_value
{
	char	**cmd;
	char	*oper;
}				t_value;

//LST_CMD
typedef struct s_lst_cmd
{
	struct s_lst_cmd	*next;
	struct s_lst_cmd	*prev;
	t_value				value;
	int					type;

}				t_lst_parser;

//LEXER TOKEN
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
	int				type;
}				t_list;

typedef struct s_char_check
{
	int		last_simple_q;
	int		last_double_q;
	char	char_valid[NB_CHAR_VALID];
	int		error;
}				t_char_check;

typedef struct s_struct
{
	int				i;
	int				is_arg;
	t_list			*lst;
	t_char_check	char_check;
	char			**temp_str;
}		t_struct;

//SIGNAL + RET FUNC
typedef struct s_sig
{
	int			ret;
	int			sigint;
	int			sigquit;
	pid_t		pid;
}				t_sig;

extern t_sig	g_glob;

/*
 * @file main/signal.c
 * @brief signal handler for main process
*/
void	global_signals_handler(void);

/**
**		lexer/lexer.c
**/
int		ft_main_lexer(char *str, t_struct *main_s, t_env *st);

/**
**		lexer/create_env.c
**/
int		ms_create_env(char **envp, t_env **st);
void	ms_clear_env(t_env **st);

/**
**		lexer/create_env_lst.c
**/
t_env	*ft_lst_new_env(char *var, char *value);
int		ft_lst_add_back_env(t_env **st, t_env *new);

/*
**		lexer/char_check_special.c
*/
int		ft_exclude_special(char c, t_struct *main);

/*
**		lexer/init.c
*/
void	ms_init_struct(t_struct *main, int argc, char **argv);

/*
**		lexer/remove_quotes.c
*/
int		ft_main_remove_quotes(t_list **lst);

/*
**		lexer/expand_var.c
*/
int		ft_main_replace_env(t_list **lst, t_env *st);

/**
**		lexer/count.c
**/
int		ft_start_read_var(char *str, int index);
int		ft_lenght_read_var(char *str, int index);
int		ft_count_char(char *str);
int		ft_count_nb_quotes(char *str);
int		ft_count_remove_quotes(char *str);

/*
**		lexer/utils.c
*/
int		ft_strjoin_3(char *dest, char *str, int start);
char	*ft_strjoin_2(char *str1, char *str2);
char	*ft_strjoin_c(char *str, char c);
int		ft_have_space(char *str);

/*
**		lexer/utils_2.c
*/
char	*ft_strcpy_2(char *str);
int		ms_strlen(const char *str);

/*
**		lexer/read_char.c
*/
void	ft_read_special(char *str, t_struct *main);
void	ft_read_cmd(char *str, t_struct *main);
int		ft_count_read_quotes(char *str, int start);

/*
**		lexer/unwanted.c
*/
char	*ft_check_quotes(char *str, t_struct *main);
char	*ft_remove_special(char *str, t_struct *main, int i);

/*
**		lexer/lst.c
*/
int		ft_lst_size(t_list *lst);
char	*ft_get_lst_str_index(t_list *lst, int index);
int		ft_lstadd(t_list **lst, t_list *new);
char	*ft_find_var(char *str, t_env *st);

/*
**		lexer/lst_2.c
*/
t_list	*ft_lst_new_join(char *content, int type);
t_list	*ft_lst_new(char *content, int type);
t_list	*ft_lst_last(t_list *lst);
int		ft_lstadd_back(t_list **lst, t_list *new);

/*
**		lexer/lst_print.c
*/
void	ft_print_env(t_env *st);
void	ft_print_lst(t_list *lst);

/*
**		lexer/free.c
*/
void	ft_free_lst(t_list **lst);
void	ft_free_all(t_list **lst);

/*
**		lexer/remove_spaces.c
*/
int		ft_remove_spaces(t_list **lst);

/*
**		lexer/set_type_cmd.c
*/
int		ft_set_type_cmd(t_list **lst);

/*
**		parse/parse.c
*/
int		ft_parse(t_list *lst, t_env *st);

/*
**		parse/exec.c
*/
void	ft_main_exec(char **complete_cmd, t_env *st, int read, int write, int read2, int write2, int type);
void	ft_is_builtin(char **complete_cmd, t_env *st, int read, int write, int read2, int write2, int type);
void	ft_is_builtin_dumb(char **complete_cmd, t_env *st, int read, int write, int read2, int write2, int type);
//void	ft_main_exec(char **complete_cmd, t_env *st, int pip[2], int pip2[2], int type);

/*
**		parse/lst.c
*/
t_lst_parser	*ft_lst_parse_new(char **cmd, char *oper, int type);
int		ft_lst_parse_add_back(t_lst_parser **lst, t_lst_parser *new);
int		ft_lst_parse_add_front(t_lst_parser **lst, t_lst_parser *new);
void	ft_print_lst_parse(t_lst_parser *lst);
void	ft_print_lst_parse_reverse(t_lst_parser *lst);
char	*ft_find_var_path(char *str, t_env *st);

/*
**		parse/tools.c
*/
char	**ft_strcpy_cmd(char **arr);

#endif
