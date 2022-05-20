#ifndef TEST_H
#define TEST_H
#define SIMPLE 0
#define DOUBLE 1

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_struct
{
	int	f_index;
	int	s_index;
	int	i;
	char ***ret;
	int	last_simple_q;
	int	last_double_q;
}		t_struct;

/*		
**		char_check.c
*/
int	ft_belong_cmd_start(char c);
int	ft_belong_cmd_end(char c);
int	ft_special_char(char c);
int	ft_exclude_char(char c);

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
char *ft_remove_char(char *str, int index);
int	ft_count_quotes(int i, int quotes, t_struct *main, int fact);
char *ft_check_unwanted(char *str, t_struct *main);



#endif
