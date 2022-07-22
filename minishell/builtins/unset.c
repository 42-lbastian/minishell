#include "../include/minishell.h"

/*
void	ft_list_remove_if(t_ListElement **st, char *var_name, char *var_value)
{
	t_ListElement	*curr;
	t_ListElement	*tmp;

    (void) var_value;
    printf("here\n");
	while (*st && !ft_strcmp_2(var_name, (*st)->var))
	{
		curr = *st;
		*st = (*st)->next;
		free(curr);
	}
	curr = *st;
	while (curr && curr->next)
	{
        printf("here\n");
        printf("%s\n", (curr)->var);
		if (!ft_strcmp_2(var_name, (curr)->var))
		{
	           	printf("on supp\n\n\n");
			tmp = curr->next;
			curr->next = tmp->next;
			free(tmp);
		}
		curr = curr->next;
	}
}
*/

void	ft_list_remove_if(t_List st, char *var_name, char *var_value)
{
	(void) var_value;
	while (st && st->next)
	{
		if (!ft_strcmp_2(var_name, st->next->var))
			st = st->next->next;

	}
}


void is_var2(char *str, t_List st)
{
	int i;
	char **ret;
    char    *var_name;
    char    *var_value;

    
   i = 0;
   if (!ft_isalpha(str[i]))
    {
        ft_putstr_fd("minishell: export: : not a valid identifier\n", 2);
		return ;
	}
    while (str[i] && (ft_isalnum(str[i]) || (str[i] == '_')))
    {
        i++;
    }
    if (str[i] && str[i] == '=')
    {
        ret = ft_trim_equal(str, '=');
        if (ret[0] == NULL)
			{
                ft_putstr_fd("bash: export: : not a valid identifier", 2);
				return ;
			}
            else
                 var_name = ret[0];
            if (ret[1] == NULL)
                var_value = NULL;
           else 
                var_value = ret[1];
        free(ret);
        if (is_in_env(st, var_name, var_value))
            ft_list_remove_if(st , var_name, var_value);
   }
}


void	ft_unset(t_List st,char **arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        is_var2(arg[i], st);
        i++;
    }
}
