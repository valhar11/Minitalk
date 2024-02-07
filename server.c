/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:59:46 by vlibert           #+#    #+#             */
/*   Updated: 2024/02/07 11:12:47 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	sig_handler(int sig)
{
	/**/
	static int	c;
	static int i;
	int	bit;
	
	if (sig == SIGUSR1)
        c |= (1 << i);
    else if (sig == SIGUSR2)
        c |= (0 << i);

	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int main(void)
{
    struct sigaction    sa;

    sa.sa_flags = 0;
    sa.sa_handler = sig_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
	printf("Here is my PID : %d\n", getpid());
    while (1)
        usleep(100);
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