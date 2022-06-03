#ifndef TEST_H
#define TEST_H
#define SIMPLE 0
#define DOUBLE 1
#define NB_CHAR_VALID 10
#define RED "\1\033[1;31m\2"
#define NORMAL "\1\x1b[0m\2"
#define NAME "minishell> "

#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
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
	t_list			*lst;
	t_char_check	char_check;
}		t_struct;



void pwd(void);
int echo(char **str);
void cd(const char *path);


/*		
**		char_check.c
*/
int	ft_belong_cmd_start(char c);
int	ft_belong_cmd_end(char c);
int	ft_special_char(char c);
int	ft_exclude_special(char c, t_struct *main);

/*
**		utils.c
*/
int	ft_strcmp(const char *str1, const char *str2);
char *ft_strjoin(char *str, char c);
char *ft_strcpy(char *str);
int	ft_strlen(const char *str);
void	ft_calloc_second(int count, size_t size, t_struct *main);
void	ft_calloc_first(int count, size_t size, t_struct *main);

/*
**		read_char.c
*/
void	ft_read_special(char *str, t_struct *main);
void	ft_read_quotes(char *str, t_struct *main, char c);
void	ft_read_cmd(char *str, t_struct *main);

/*
**		unwanted.c
*/
char *ft_check_quotes(char *str, t_struct *main);
char *ft_remove_special(char *str, t_struct *main);

/*
**		list.c
*/
t_list	*ft_lst_new(char *content);
t_list *ft_lst_last(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_print_lst(t_list *lst);

/*
**		free.c
*/
void	ft_free_lst(t_list **lst);


#endif
