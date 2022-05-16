#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main()
{
	int end;
	char *str;

	end = 1;
	while (end)
	{
		printf("$ ");
		str = readline("");
		if (ft_strlen(str) == 0)
			end = 0;
		else
			printf("|%s|\n", str);	
	}
	printf("\n");
}
