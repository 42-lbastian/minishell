#include "test.h"

void	ft_lexer(char *str, t_struct *main)
{
	main->i = 0;
	main->f_index = 0;
	main->s_index = 0;
	ft_calloc_first(16, sizeof(char **), main);
	ft_calloc_second(16, sizeof(char *), main);
	main->ret[1] = NULL;
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
	int i;
	int j;

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
	char *str_ret;

	str_ret = ft_check_unwanted(str, main);
	ft_lexer(str_ret, main);
}

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

int main()
{
	char *str_read;
	t_struct *main;

	main = malloc(sizeof(t_struct));
	while (1)
	{
		str_read = readline("");
		if (ft_strcmp(str_read, "exit") == 0)
			break ;
		ft_main_lexer(str_read, main);
		//parser
		ft_print_arr(main->ret);
		if (ft_strlen(str_read) != 0)
			add_history(str_read);
		free (str_read);
	}
	ft_free(main);
	clear_history();
	return (0);
}
