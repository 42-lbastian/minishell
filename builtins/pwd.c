#include "../libft/libft.h"

void    pwd(void)
{
    char    cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
       ft_printf("%s\n", cwd);
    }
}

int main()
{
    pwd();
    return (0);
}