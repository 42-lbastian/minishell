#include "../libft/libft.h"
#include "test.h"

void    pwd(void)
{
    char    cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
       ft_printf("%s\n", cwd);
    }
}
