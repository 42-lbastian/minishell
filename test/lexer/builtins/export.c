#include "../include/minishell.h"

void is_var(t_List sta, char *str, char *var_name, char *var_value)
{
    int i;
    char **ret[1];

    i = 0;
    if (!ft_isalpha(str[i]))
        return (0);
    while (str[i] && (!ft_isalnum(str[i]) || !(str[i] == '_')))
    {
        i++;
    }
    if (str[i] && str[i] == '=')
        var_name = ft_substr(str, 0 , i - 1);
    var_value = ft_substr(ft_substr, i, ft_strlen(str));
    ret[0] = var_name;
    ret[1] = var_value;
    add_list(var_name ,sta);    
    add_list(var_value ,sta);

}


void    pars_export(char **arg)
{
    is_var(arg);
}
