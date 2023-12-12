/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:59:46 by vlibert           #+#    #+#             */
/*   Updated: 2023/12/12 11:55:27 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	printf("Youpi");
	//if(sig == SIGUSER1)
		
	//if (sig == SIGUSER2)
	
}

int main()
{
	struct	sigaction sa;
	pid_t	pid;
	
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	printf("Here is my PID : %i", pid);
	while(1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		sleep(100);
	}
}