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

void	change_pwd(t_List st, char *old)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 999999);
    is_var(ft_strjoin("OLDPWD=", old), st);
	is_var(ft_strjoin("PWD=", cwd), st);
	free(cwd);
}

void	home(t_List st, char *buf)
{
	char	*home;

	home = search_in_env(st, "HOME");
	if (home)
	{
		chdir(home);
		change_pwd(st, buf);
	}
	else
	    ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	free(buf);
}

void    path_error( char *path, char *cwd)
{
    ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	free(cwd);
	glob.ret = 127;
}

void cd(t_List st,  char *path)
{
    char    *cwd;

    cwd = NULL;
	cwd = getcwd(cwd, 999999); 

    if (path == NULL)
        return (home(st, cwd));
    else if (chdir(path))
        return (path_error(path, cwd));
    else
    {
        change_pwd(st, cwd);
        free(cwd);
    }
}
