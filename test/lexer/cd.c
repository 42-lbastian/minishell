#include "test.h"


void cd(const char *path)
{
    int c;

    pwd();
    ft_printf("\n");
    c = chdir(path);
     ft_printf("%d",c);
    if (c != 0)
        return ;
   
    ft_printf("\n");
    pwd();
}