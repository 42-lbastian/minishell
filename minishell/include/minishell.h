#ifndef MINISHELL_H
#define MINISHELL_H
#define SIMPLE 0
#define DOUBLE 1
#define NB_CHAR_VALID 12
#define RED "\1\033[1;31m\2"
#define NORMAL "\1\x1b[0m\2"
#define NAME "minishell> "
#define	OPER 1
#define CMD 2
#define FLAG 3
#define ARG 4

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct t_ListElement
{
	char			    	*var;
    char                    *value;
	struct t_ListElement	*next;
}t_ListElement,	*t_List;

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
	int				type;
}				t_list;

typedef	struct	s_char_check
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

/**
**		pwd.c
**/
void	pwd(void);

/**
**		echo.c
**/
int		echo(char **str);

/**
**		cd.c
**/
void	cd(t_List st, const char *path);

char	**ft_trim_equal(char const *s, char charset);
void    ft_export(t_List st, char **arg);
void	push_list_back(t_List *st, char *var_name, char *var_value);


/**
**		env.c
**/
void is_var(char *str, t_List st);
void    ft_export(t_List st, char **arg);
void	create_env(char **envp);
void print_env(t_List st);
t_List	add_list(char **tab, t_List sta);

/**
**		utils_env.c
**/
char	**ft_trim_equal(char const *s, char charset);

/*		
**		char_check.c
*/
int	ft_belong_cmd_start(char c);
int	ft_belong_cmd_end(char c);
int	ft_belong_arg_end(char c);
int	ft_is_alpha(char c);

/*
**		char_check_special.c
*/
int	ft_special_char(char c);
int	ft_exclude_special(char c, t_struct *main);

/*
**		init.c
*/
void	ft_init_struct(t_struct *main, int argc, char **argv);
void	ft_fill_tab_char(t_struct *main, char *str);

/*
**		utils.c
*/
int	ft_strcmp_2(const char *str1, const char *str2);
char *ft_strcpy_2(char *str);
int	ft_strlen(const char *str);

/*
**		read_char.c
*/
void	ft_read_special(char *str, t_struct *main);
void	ft_read_quotes(char *str, t_struct *main, char c);
void	ft_read_cmd(char *str, t_struct *main);
void	ft_read_arg(char *str, t_struct *main);
void	ft_read_flag(char *str, t_struct *main);

/*
**		unwanted.c
*/
char *ft_check_quotes(char *str, t_struct *main);
char *ft_remove_special(char *str, t_struct *main, int i);

/*
**		list.c
*/
t_list	*ft_lst_new(char *content, int type);
t_list *ft_lst_last(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_print_lst(t_list *lst);
int		ft_lst_size(t_list *lst);
char	*ft_get_lst_str_index(t_list *lst, int index);

/*
**		free.c
*/
void	ft_free_lst(t_list **lst);

/*
**		remove_spaces.c
*/
void	ft_remove_spaces(t_list **lst);

#endif
