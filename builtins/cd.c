#include "../libft/libft.h"
void cd(const char *path)
{
    int c;
    
    c = chdir(path);
    ft_printf("%d",c);
}


int main(int ac, char **av)
{
    cd(av[1]);
    return (0);
}