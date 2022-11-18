#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	//write(fd, argv[2], ft_strlen(argv[2]));
	dprintf(fd, "%s", argv[2]);
	return (0);
}
