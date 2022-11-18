#include "../include/minishell.h"

void	ft_fill_tab_char(t_struct *main, char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != NB_CHAR_VALID)
	{
		printf("ERROR NB_CHAR\n");
		exit(0);
	}
	while (str[i])
	{
		main->char_check.char_valid[i] = str[i];
		i++;
	}
}

void	ft_init_struct(t_struct *main, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	main->lst = NULL;
	main->char_check.error = 0;
	main->char_check.last_double_q = 0;
	main->char_check.last_simple_q = 0;
	ft_fill_tab_char(main, "=/|<>.'\" $?-");
}
