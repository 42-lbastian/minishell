#include "../include/minishell.h"


void	ft_list_remove_if(t_List st, char *var_name)
{
	t_ListElement *prev;
	t_ListElement *tmp;

	if (st && !ft_strcmp_2(var_name, st->var))
	{
		tmp = st;
		st = st->next;
		free(tmp);
	}
	prev = st;
	tmp = st->next;
	while (tmp && tmp->next)
	{
		if (!ft_strcmp_2(var_name, tmp->var))
		{
			prev->next = tmp->next;
			free(tmp->var);
			free(tmp->value);
			free(tmp);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	if (!ft_strcmp_2(var_name, tmp->var))
	{
		prev->next = NULL;
		free(tmp->var);
		free(tmp->value);
		free(tmp);
	}
}


void is_var2(char *str, t_List st)
{
	int i;
    char    *var_name;

    
   i = 0;
   if (!ft_isalpha(str[i]))
    {
        ft_putstr_fd("minishell: unset: : not a valid identifier\n", 2);
		return ;
	}
    while (str[i] && (ft_isalnum(str[i]) || (str[i] == '_')))
    {
        i++;
    }
		
    var_name = str;
	ft_list_remove_if(st , var_name);
   
}


void	ft_unset(t_List st,char **arg)
{
    int i;

    i = 1;
    while (arg[i])
    {
        is_var2(arg[i], st);
        i++;
    }
}
