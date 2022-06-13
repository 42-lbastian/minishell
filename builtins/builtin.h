#ifndef builtin
# define BUILTIN_H
# include <unistd.h>
# include <stdlib.h>
#include "../libft/libft.h"

typedef struct t_ListElement
{
	char			    	*var;
    char                    *value;
	struct t_ListElement	*next;
}t_ListElement,	*t_List;

void    pwd(void);
char	**ft_trim_equal(char const *s, char charset);
void 	env(char **envp);
t_List	add_list(char **tab, t_List sta);

#endif