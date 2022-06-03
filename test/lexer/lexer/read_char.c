#include "../include/minishell.h"

void	ft_read_special(char *str, t_struct *main)
{
	int	y;

	y = 0;
	while (str[main->i + y] && ft_special_char(str[main->i + y]))
		y++;
	ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y)));
	if (!(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
//	if (str[main->i])
//		main->i++;
/*	while (ft_special_char(str[main->i]))
	{
		main->ret[main->s_index][main->f_index] = ft_strjoin(main->ret[main->s_index][main->f_index], str[main->i]);
		main->i++;
	}
	main->ret[main->s_index][main->f_index + 1] = NULL;
	main->f_index = 0;
	main->s_index++;
	ft_calloc_second(16, sizeof(char*), main);
	main->ret[main->s_index + 1] = NULL;
	main->ret[main->s_index][0] = NULL;
	*/
}

void	ft_read_quotes(char *str, t_struct *main, char c)
{
	int	y;

	y = 1;
	while (str[main->i + y] && str[main->i + y] != c)
		y++;
	ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y + 1)));
	if (!(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
	if (str[main->i])
		main->i++;
/*	main->ret[main->s_index][main->f_index] = ft_strjoin(main->ret[main->s_index][main->f_index], str[main->i]);
	main->i++;
	while (str[main->i] != c && str[main->i])
	{
		if (!(str[main->i + 1] && str[main->i] == '\\' && str[main->i + 1] == c))
		main->ret[main->s_index][main->f_index] = ft_strjoin(main->ret[main->s_index][main->f_index], str[main->i]);
		main->i++;
	}
	main->ret[main->s_index][main->f_index] = ft_strjoin(main->ret[main->s_index][main->f_index], str[main->i]);
	main->i++;
	main->f_index++;
	main->ret[main->s_index][main->f_index] = NULL;
*/
}

void	ft_read_cmd(char *str, t_struct *main)
{
	int	y;

	y = 1;
	while (str[main->i + y] && ft_belong_cmd_end(str[main->i + y]))
		y++;
	ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y)));
	if (!(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
//	if (str[main->i])
//		main->i++;
/*	while (ft_belong_cmd_end(str[main->i]) && str[main->i])
	{
		main->ret[main->s_index][main->f_index] = ft_strjoin(main->ret[main->s_index][main->f_index], str[main->i]);
		main->i++;
	}
	main->f_index++;
	main->ret[main->s_index][main->f_index] = NULL;
*/
}
