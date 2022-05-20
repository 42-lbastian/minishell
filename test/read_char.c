#include "test.h"

void	ft_read_special(char *str, t_struct *main)
{
	while (ft_special_char(str[main->i]))
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
}

void	ft_read_quotes(char *str, t_struct *main, char c)
{
	main->ret[main->s_index][main->f_index] = ft_strjoin(main->ret[main->s_index][main->f_index], str[main->i]);
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
}

void	ft_read_cmd(char *str, t_struct *main)
{
	while (ft_belong_cmd_end(str[main->i]) && str[main->i])
	{
		main->ret[main->s_index][main->f_index] = ft_strjoin(main->ret[main->s_index][main->f_index], str[main->i]);
		main->i++;
	}
	main->f_index++;
	main->ret[main->s_index][main->f_index] = NULL;
}
