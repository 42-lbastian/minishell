#include "../include/minishell.h"

int		ft_count_nb_quotes(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_interpret_env(char *str, t_List st)
{
	(void)st;
	printf("STR %s\n", str + 2);
	return (str);
}

int		ft_lenght_read_var(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] == '"' || str[i] == '\'')
			i++;
		if (str[i] && str[i] == '$')
		{
			size++;
			while (str[i] && str[i] != '"' && str[i] != '\'')
			{
				size++;
				i++;
			}
		}
		else
			i++;
	}
	return (size - 1);
}

int 	ft_start_read_var(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == '"' || str[i] == '\'' ))
		i++;
	return (i);
}

int		ft_size_env_var(t_List st, char *str)
{
	(void)st;

	printf("Substr %s\n", ft_substr(str, ft_start_read_var(str), ft_lenght_read_var(str)));
	return (0);
}

void	ft_replace_env(char *str, t_List st)
{
	int size;

	size = ft_count_nb_quotes(str);
	size += ft_size_env_var(st, str);
	//(*lst)->content = ft_interpret_env((*lst)->content, st);
}

int		ft_env_var(t_list **lst, t_List st)
{
	t_list *temp;

	(void)st;

	temp = (*lst);
	while (lst && (*lst))
	{
		if ((*lst)->type == ARG)
		{
			if ((*lst)->content[0] != '\'')
				ft_replace_env((*lst)->content, st);
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}
