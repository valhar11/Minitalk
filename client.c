/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:59:53 by vlibert           #+#    #+#             */
/*   Updated: 2024/02/06 12:42:46 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		while (argv[2][i])
		{
			send_message(pid, argv[2][i]);
			i++;
		}
	}
	else
		printf("Error : The command should look like this\n\t./client <PID> <MESSAGE>");
}