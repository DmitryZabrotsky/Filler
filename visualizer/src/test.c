#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i = 1;
	system("clear");
	while (i != 6)
	{
		system("clear");
		printf("%s\n", av[i]);
		usleep(125000);
		i++;
	}
}