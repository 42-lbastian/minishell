#include "../include/minishell.h"

void cd(t_List st, const char *path)
{
    int c;
    char    cwd[1024];
    char *oldpath;

    
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
