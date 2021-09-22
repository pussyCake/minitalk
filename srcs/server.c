/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:45:12 by pantigon          #+#    #+#             */
/*   Updated: 2021/09/22 18:57:41 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "libft.h"

void	change_signal(int signal, siginfo_t *siginfo, void *context)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("1\n", 1);
	else if (signal == SIGUSR2)
		ft_putstr_fd("0\n", 1);
	(void)context;
	kill(siginfo->si_pid, SIGUSR1);
	// printf("OK\n");
	// char	c;
	// int		i;

	// i = 8;
	// while (i > 0)
	// {
	// 	if (signal == SIGUSR1)
	// 	{

	// 	}
	// 	else
	// 	{
			
	// 	}
	// 	--i;
	// }
}

int	main(void)
{
	struct sigaction sig;

	ft_putstr_fd("server id: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = change_signal;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (1);
}