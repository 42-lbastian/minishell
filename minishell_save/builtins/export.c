#include "../include/minishell.h"

int is_in_env(t_List st, char *var_name, char *var_value)
{
	if (st == NULL)
		return 0;
	while (st !=NULL)
	{
        if (!ft_strcmp_2(var_name, st->var))
        {
            st->var = var_name;
	        st->value = var_value;
            return (1);
        }
		st = st->next;
	}
    return (0);
}

void is_var(char *str, t_List st)
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
        if (!is_in_env(st, var_name, var_value))
            push_list_back(&st , var_name, var_value);
   }
}

void    export_only(t_List st)
{
    int	i;

	i = 0;
	if (st == NULL)
		return ;
	while (st !=NULL)
	{
        printf("%s=", st->var);
        printf("%s\n", st->value);
		st = st->next;
		i++;
	}
}

void    ft_export(t_List st, char **arg)
{
    int i;

    i = 0;
    if (arg[1] == NULL)
    {
        printf("le tri\n");
    }
    while (arg[i])
    {
        is_var(arg[i], st);
        i++;
    }
}
