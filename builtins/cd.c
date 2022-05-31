#include "../libft/libft.h"
#include "builtin.h"

void cd(const char *path)
{
    int c;

    pwd();
    ft_printf("\n");
    c = chdir(path);
    if (c != 0)
        return ;
    ft_printf("%d",c);
    ft_printf("\n");
    pwd();
}


int main(int ac, char **av)
{
    cd(av[1]);
    return (0);
}