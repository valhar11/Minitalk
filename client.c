#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void send_message(int pid, char c)
{
	int bit;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
	}
}

int main (int argc, char **argv)
{
	int pid;
	int i;
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		//char *str = argv[2];

			printf("YO\n");
		while (printf("YO\n") && argv[2][i] && printf("YO\n"))
		{
			send_message(pid, argv[2][i]);
			i++;
		}
	}
	else
		printf("Error : The command should look like this\n\t./client <PID> <MESSAGE>");
}