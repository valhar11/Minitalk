/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:59:46 by vlibert           #+#    #+#             */
/*   Updated: 2024/02/06 12:56:43 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	sig_handler(int sig)
{
	char c;
	int i;

	i = 0;
	while (i < 8)
	{
		if(sig == SIGUSR1)
			c << 1;
		else
			c |= (c << bit);
			
		
	}
}
/**/
int main(void)
{
    struct sigaction    sa, osa;

    sa.sa_flags = 0;
    sa.sa_handler = sig_handler;
    sigaction(SIGUSR1, &sa, &osa);
    sigaction(SIGUSR2, &sa, &osa);
	printf("Here is my PID : %d\n", getpid());
    while (1)
        usleep(1);
    return(0);
}
/*
int main()
{
	struct	sigaction starfoula;
	sigset_t	mask;
	
	printf("Here is my PID : %d", getpid());
	starfoula.sa_flags = SA_SIGINFO;
	starfoula.sa_sigaction = sig_handler;
	
	while(1)
	{
		//usleep(1000000000);
	}

}*/