#include "../include/minishell.h"

void	ft_cmd(t_struct *main_s, t_List st)
{
	if (ft_strcmp_2(main_s->temp_str[0], "echo") == 0)
		echo(main_s->temp_str);
	if (ft_strcmp_2(main_s->temp_str[0], "cd") == 0)
		cd(st, main_s->temp_str[1]);
	if (ft_strcmp_2(main_s->temp_str[0], "pwd") == 0)
		pwd();
	if (ft_strcmp_2(main_s->temp_str[0], "env") == 0)
		print_env(st);
	if (ft_strcmp_2(main_s->temp_str[0], "export") == 0)
		ft_export(st, main_s->temp_str);
}

void	ft_temp_test_cmd(t_struct *main_s)
{
	int	i;
	int	size;

	size = ft_lst_size(main_s->lst);
	i = 0;
	main_s->temp_str = malloc(sizeof(char *) * (size + 1));
	main_s->temp_str[size] = NULL;
	while (i < size)
	{
		if (ft_strlen(ft_get_lst_str_index(main_s->lst, i)) == 0)
			main_s->temp_str[i] = NULL;
		else
			main_s->temp_str[i]
				= ft_strcpy_2(ft_get_lst_str_index(main_s->lst, i));
		i++;
	}
}

int	ft_main_s_action(t_struct *main_s, char *str_read, t_List st)
{
	while (1)
	{
		//str_read = readline(RED NAME NORMAL);
		str_read = readline(NAME);
		if (!str_read)
			return (0);
		if (ft_strcmp_2(str_read, "exit") == 0)
			break ;
		if (ft_strlen(str_read) != 0)
			add_history(str_read);
		if (ft_main_s_lexer(str_read, main_s, st))
		{
			ft_putstr_fd("Malloc error\n", 2);
			ft_free_lst(&main_s->lst);
			break ;
		}
		//parser
		ft_temp_test_cmd(main_s);
		ft_cmd(main_s, st);
		ft_print_lst(main_s->lst);
		ft_free_lst(&main_s->lst);
	}
	free(str_read);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char		*str_read;
	t_struct	*main_s;
	t_List		st;

	st = NULL;
	st = add_list(envp, st);
	main_s = malloc(sizeof(t_struct));
	if (!main_s)
		return (1);
	str_read = NULL;
	ft_init_struct(main_s, argc, argv);
	ft_main_s_action(main_s, str_read, st);
	free(main_s);
	clear_history();
	return (0);
}