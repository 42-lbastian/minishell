#include "../include/minishell.h"

void	ft_read_special(char *str, t_struct *main)
{
	int	y;

	y = 0;
	while (str[main->i + y] && ft_special_char(str[main->i + y]))
		y++;
	ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y), OPER));
	if (!(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
}

void	ft_read_quotes(char *str, t_struct *main, char c)
{
	int	y;

	y = 1;
	while (str[main->i + y] && str[main->i + y] != c)
		y++;
	ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y + 1), ARG));
	if (!(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
	if (str[main->i])
		main->i++;
}

void	ft_read_cmd(char *str, t_struct *main)
{
	int	y;

	y = 1;
	while (str[main->i + y] && ft_belong_cmd_end(str[main->i + y]))
		y++;
	ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y), CMD));
	if (!(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
}

void	ft_read_arg(char *str, t_struct *main)
{
	int	y;

	main->is_arg = 0;
	y = 1;
	while (str[main->i + y] && ft_belong_arg_end(str[main->i + y]))
		y++;
	if (str[main->i + y - 1] == ' ')
		y--;
	ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y), ARG));
	if (!(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
}

void	ft_read_flag(char *str, t_struct *main)
{
	int y;

	y = 1;
	main->is_arg = 1;
	while (str[main->i + y])
	{
		if (ft_belong_cmd_end(str[main->i + y]) == 0)
		{
			while (str[main->i + y] && str[main->i + y] == ' ')
				y++;
			if (!(str[main->i + y] && str[main->i + y] == '-'))
			{
				y--;
				break;
			}
		}
		y++;
	}
	ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y), FLAG));
	if (!(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
}
