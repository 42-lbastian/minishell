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
	str = ft_remove_special(str, main, 0);
	ret = ft_lexer(str, main);
	free(str);
	return (ret);
}

void	ft_cmd(t_struct *main, char **envp)
{
	(void)main;
	(void)envp;
}

int	ft_main_action(t_struct *main, char *str_read, char **envp)
{
	while (1)
	{
		str_read = readline(RED NAME NORMAL);
		if (!str_read)
			return (0);
		if (ft_strcmp(str_read, "exit") == 0)
			break ;
		if (ft_strlen(str_read) != 0)
			add_history(str_read);
		if (ft_main_lexer(str_read, main))
		{
			ft_free_lst(&main->lst);
			break ;
		}
		//parser
		ft_cmd(main, envp);
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

	main = malloc(sizeof(t_struct));
	if (!main)
		return (1);
	str_read = NULL;
	ft_init_struct(main, argc, argv);
	ft_main_action(main, str_read, envp);
	free(main);
	clear_history();
	return (0);
}
