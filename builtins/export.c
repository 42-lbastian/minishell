#include "builtin.h"

char **is_var(char *str, char *var_name, char *var_value)
{
    int i;

    i = 0;
    if (!ft_isalpha(str[i]))
        return (0);
    while (str[i] && (!ft_isalnum(str[i]) || !(str[i] == '_')))
    {
        i++;
    }
    if (str[i] && str[i] == '=')
        var_name = ft_substr(str, 0 , i - 1);
    
}


void    pars_export(char **arg)
{
    
}