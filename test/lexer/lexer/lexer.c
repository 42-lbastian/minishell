#include "../include/minishell.h"

void	ft_lexer(char *str, t_struct *main)
{
	main->i = 0;
	main->f_index = 0;
	main->s_index = 0;
	//Fix Calloc resize
//	ft_calloc_first(16, sizeof(char **), main);
//	ft_calloc_second(16, sizeof(char *), main);
//	main->ret[1] = NULL;
	while (str[main->i])
	{
		if (ft_belong_cmd_start(str[main->i]))
			ft_read_cmd(str, main);
		if (str[main->i] == '"')
			ft_read_quotes(str, main, '"');
		if (str[main->i] == '\'')
			ft_read_quotes(str, main, '\'');
		if (ft_special_char(str[main->i]))
			ft_read_special(str, main);
		while (str[main->i] == ' ' && str[main->i])
			main->i++;
	}
	free(str);
}

void	ft_print_arr(char ***arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			printf("%s\t", arr[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	ft_main_lexer(char *str, t_struct *main)
{	
	char	*str_ret;

	str_ret = ft_check_quotes(str, main);
	str_ret = ft_remove_special(str_ret, main);
	ft_lexer(str_ret, main);
}

/*
void	ft_free(t_struct *main)
{
	int i;
	int j;

	i = 0;
	while (main->ret[i])
	{
		j = 0;
		while (main->ret[i][j])
		{
			free(main->ret[i][j]);
			j++;
		}
		free(main->ret[i]);
		i++;
	}
	free(main->ret);
	free(main);
}
*/

void	ft_fill_tab_char(t_struct *main, char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > NB_CHAR_VALID || ft_strlen(str) < NB_CHAR_VALID)
	{
		printf("ERROR NB_CHAR\n");
		exit(0);
	}
	while (str[i])
	{
		main->char_valid[i] = str[i];
		i++;
	}
}

/*
void	ft_print_line(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		printf("%s\t", str[i]);
		i++;
	}
	printf("\n");
}
*/
void	ft_cmd(t_struct *main)
{
	(void)main;
/*	if (ft_strcmp(main->ret[0][0], "echo") == 0)
	{
		echo(main->ret[0]);
	}	//builtin echo
	else if (ft_strcmp(main->ret[0][0], "cd") == 0)
	{
		cd(main->ret[0][1]);
	}	//builtin cd
	else if (ft_strcmp(main->ret[0][0], "pwd") == 0)
	{
		pwd();
	}	//builtin pwd
	else if (ft_strcmp(main->ret[0][0], "export") == 0)
	{}	//builtin export
	else if (ft_strcmp(main->ret[0][0], "unset") == 0)
	{}	//builtin unset
	else if (ft_strcmp(main->ret[0][0], "env") == 0)
	{}	//builtin env
	*/
}

int	main(int argc, char **argv, char **envp)
{
	char		*str_read;
	t_struct	*main;

	main = malloc(sizeof(t_struct));
	main->lst = NULL;
	ft_fill_tab_char(main, "/|<>.'\" $?");
	while (1)
	{
		str_read = readline(RED NAME NORMAL);
		if (ft_strcmp(str_read, "exit") == 0)
			break ;
		ft_main_lexer(str_read, main);
		//parser
	//	ft_cmd(main);
		ft_print_lst(main->lst);
		ft_free_lst(&main->lst);
//		ft_print_arr(main->ret);
		if (ft_strlen(str_read) != 0)
			add_history(str_read);
		free (str_read);
	}
	free(str_read);
	free(main);
//	ft_free(main);
	clear_history();
	return (0);
}
