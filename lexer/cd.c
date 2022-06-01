#include "test.h"


void cd(char *path)
{
    int c;

    c = chdir(path);
    if (c != 0)
        return ;
}