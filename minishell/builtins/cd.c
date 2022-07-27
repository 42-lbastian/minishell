#include "../include/minishell.h"

char    *search_in_env(t_List st, char *str)
{   
    t_List tmp;

    tmp = st;
    while (tmp != NULL)
    {
        if (!ft_strcmp_2(str, tmp->var))
        {
            return (tmp->value);
        }
        tmp = tmp->next;
    }
    return (NULL);
}


void cd(t_List st, const char *path)
{
    int c;
    char    cwd[1024];
    char *oldpath;


    if (path == NULL || path[0] == '~')
    {
        
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            oldpath = ft_strjoin("OLDPWD=", cwd);
            is_var(oldpath, st);
        }
        oldpath = search_in_env(st, "HOME");
        c = chdir(oldpath);
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            oldpath = ft_strjoin("PWD=", cwd);
            is_var(oldpath, st);
        }
    } 
    else
    {
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            oldpath = ft_strjoin("OLDPWD=", cwd);
            is_var(oldpath, st);
        }
        c = chdir(path);
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            oldpath = ft_strjoin("PWD=", cwd);
            is_var(oldpath, st);
        }
        if (c != 0)
           return ;
    }   
}
