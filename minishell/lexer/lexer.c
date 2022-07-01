#include "../include/minishell.h"

int	ft_lexer(char *str, t_struct *main)
{
	main->i = 0;
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
		if (main->char_check.error == 1)
			return (1);
	}
	return (0);
}

int	ft_main_lexer(char *str, t_struct *main)
{	
	int		ret;

	str = ft_check_quotes(str, main);
	str = ft_check_quotes(str, main);
	str = ft_remove_special(str, main, 0);
	ret = ft_lexer(str, main);
	free(str);
	return (ret);
}

void	ft_cmd(t_struct *main, t_List st)
{
	if (ft_strcmp_2(main->temp_str[0], "echo") == 0)
		echo(main->temp_str);
	if (ft_strcmp_2(main->temp_str[0], "cd") == 0)
		cd(main->temp_str[1]);
	if (ft_strcmp_2(main->temp_str[0], "pwd") == 0)
		pwd();	
	if (ft_strcmp_2(main->temp_str[0], "env") == 0)
		print_env(st);
	if (ft_strcmp_2(main->temp_str[0], "export") == 0)
		ft_export(st, main->temp_str);
}

void	ft_temp_test_cmd(t_struct *main)
{
	int i;
	int size;


	size = ft_lst_size(main->lst);
	i = 0;
	main->temp_str = malloc(sizeof(char*) * (size + 1));
	main->temp_str[size] = NULL;
	while (i < size)
	{
		main->temp_str[i] = ft_strcpy_2(ft_get_lst_str_index(main->lst, i));
		i++;
	}
}

int	ft_main_action(t_struct *main, char *str_read, t_List st)
{
	while (1)
	{
		str_read = readline(RED NAME NORMAL);
		if (!str_read)
			return (0);
		if (ft_strcmp_2(str_read, "exit") == 0)
			break ;
		if (ft_strlen(str_read) != 0)
			add_history(str_read);
		if (ft_main_lexer(str_read, main))
		{
			ft_free_lst(&main->lst);
			break ;
		}
		//parser
		ft_temp_test_cmd(main);
		ft_cmd(main, st);
		ft_print_lst(main->lst);
		ft_free_lst(&main->lst);
	}
	free(str_read);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char		*str_read;
	t_struct	*main;
	t_List st;

    st = NULL;
    st = add_list(envp, st);
	main = malloc(sizeof(t_struct));
	if (!main)
		return (1);
	str_read = NULL;
	ft_init_struct(main, argc, argv);
	ft_main_action(main, str_read, st);
	free(main);
	clear_history();
	return (0);
}
