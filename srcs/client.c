/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:45:16 by pantigon          #+#    #+#             */
/*   Updated: 2021/09/22 14:33:15 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

int	error_msg(char *msg)
{
	if (msg)
		write(1, msg, ft_strlen(msg));
	return (1);
}

void	change_signal(int signal, siginfo_t *siginfo, void *context)
{
	
}

int	main(int ac, char **av)
{
	struct sigaction sig;

	if (ac != 3)
		return (error_msg("ERROR: client request fail!!\n"));
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = change_signal;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	kill(ft_atoi(av[1]), SIGUSR1);
	return (1);
}