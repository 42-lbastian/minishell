#include <unistd.h>
#include <stdio.h>

void	ft_dup(int fd)
{
	int pip[2];

	pipe(pip);
	if (fd == 1)
		ft_dup(pip[1]);
	printf("fd %d\n", fd);
	dup2(fd, 1);
	printf("Toto\n");
}

int main()
{
	ft_dup(1);
}
