#include "../include/minishell.h"

void	ft_set_type_oper(t_struct *main)
{
	if (ft_strcmp_2(ft_lst_last(main->lst)->content, "|") == 0)
		ft_lst_last(main->lst)->type = PIPE;
	else if (ft_strcmp_2(ft_lst_last(main->lst)->content, "<") == 0)
		ft_lst_last(main->lst)->type = FILE_IN;
	else if (ft_strcmp_2(ft_lst_last(main->lst)->content, ">") == 0)
		ft_lst_last(main->lst)->type = FILE_OUT_OVER;
	else if (ft_strcmp_2(ft_lst_last(main->lst)->content, ">>") == 0)
		ft_lst_last(main->lst)->type = FILE_OUT_APP;
	else if (ft_strcmp_2(ft_lst_last(main->lst)->content, "<<") == 0)
		ft_lst_last(main->lst)->type = HERE_DOC;
	else
		main->char_check.error = 1;	
}

void	ft_read_special(char *str, t_struct *main)
{
	int	y;
	int	error;

	y = 0;
	main->is_arg = 0;
	while (str[main->i + y] && ft_special_char(str[main->i + y]))
		y++;
	error = ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y),
				DEFAULT));
	if (error || !(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	else
		ft_set_type_oper(main);
	main->i += y;
}

void	ft_read_quotes(char *str, t_struct *main, char c)
{
	int	y;
	int	error;
	int	quotes;

	(void)c;
	quotes = 0;
	y = 0;
	while (str[main->i + y])
	{
		if (str[main->i + y] == '"' && quotes == 0)
			quotes = 1;
		else if (str[main->i + y] == '\'' && quotes == 0)
			quotes = 2;
		else if ((str[main->i + y] == '"' && quotes == 1)
			|| (str[main->i + y] == '\'' && quotes == 2))
			quotes = 0;
		if (ft_belong_cmd_end(str[main->i + y]) == 0 && quotes == 0)
			break;
		y++;
	}
	if (str[main->i + y] == ' ')
		y--;
	error = ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y
					+ 1), CMD));
	if (error || !(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
	if (str[main->i])
		main->i++;
}

void	ft_read_cmd(char *str, t_struct *main)
{
	int	y;
	int	error;

	//main->is_arg = 1;
	y = 1;
	while (str[main->i + y] && ft_belong_cmd_end(str[main->i + y]))
		y++;
	error = ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y),
				CMD));
	if (error || !(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
}

void	ft_read_arg(char *str, t_struct *main)
{
	int	y;
	int	error;

	y = 1;
	while (str[main->i + y] && ft_belong_cmd_end(str[main->i + y]))
		y++;
	//if (str[main->i + y - 1] == ' ')
	//	y--;
	error = ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y),
				CMD));
	if (error || !(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
}
