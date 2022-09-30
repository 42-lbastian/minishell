#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd;

	fd = open("TOTA", O_WRONLY | O_CREAT, 0666);
	dup2(fd, 1);
	printf("%s\n", argv[1]);
	//write(fd, "TITI", 4);
	close(fd);
	return (0);
}
