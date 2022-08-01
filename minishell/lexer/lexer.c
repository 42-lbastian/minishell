#include "../include/minishell.h"

int	ft_lexer(char *str, t_struct *main_s)
{
	main_s->i = 0;
	main_s->is_arg = 0;
	while (str[main_s->i])
	{
		if (str[main_s->i] && ft_belong_cmd_start(str[main_s->i])
			&& main_s->is_arg == 0)
			ft_read_cmd(str, main_s, CMD);
		if (str[main_s->i] && str[main_s->i] == '-')
			ft_read_cmd(str, main_s, FLAG);
		if (str[main_s->i] && ft_belong_cmd_start(str[main_s->i])
			&& main_s->is_arg == 1)
			ft_read_arg(str, main_s);
		if (str[main_s->i] && str[main_s->i] == '"')
			ft_read_quotes(str, main_s, '"');
		if (str[main_s->i] && str[main_s->i] == '\'')
			ft_read_quotes(str, main_s, '\'');
		if (str[main_s->i] && ft_special_char(str[main_s->i]))
			ft_read_special(str, main_s);
		while (str[main_s->i] && str[main_s->i] == ' ')
			main_s->i++;
		if (main_s->char_check.error == 1)
			return (1);
	}
	return (0);
}

int	ft_main_s_lexer(char *str, t_struct *main_s, t_List st)
{	
	int		ret;

	str = ft_check_quotes(str, main_s);
	str = ft_check_quotes(str, main_s);
	str = ft_remove_special(str, main_s, 0);
	ret = ft_lexer(str, main_s);
	if (ret == 0)
		ret = ft_remove_spaces(&main_s->lst);
	if (ret == 0)
		ret = ft_replace_arg(&main_s->lst, st);
	//free(str);
	return (ret);
}
