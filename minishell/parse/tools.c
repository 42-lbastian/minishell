#include "../include/minishell.h"

char	**ms_strcpy_cmd(char **arr)
{
	char	**ret;
	int 	i;
	
	i = 0;
	while (arr[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	ret[i] = NULL;
	i = 0;
	while (arr[i])
	{
		ret[i] = ms_strcpy_2(arr[i]);
		if (!ret[i])
		{
			//FREE ALL BEFORE FAIL
			return (NULL);
		}
		i++;
	}
	return (ret);
}
