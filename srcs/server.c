/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:45:12 by pantigon          #+#    #+#             */
/*   Updated: 2021/09/23 18:57:41 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	init_data(void)
{
	g_data.byte = 0;
	g_data.chr = 0;
}

void	client_id(pid_t cid)
{
	g_data.cid = cid;
	ft_putstr_fd("client [", 1);
	ft_putnbr_fd(cid, 1);
	ft_putstr_fd("]: ", 1);
}

void	change_signal(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (g_data.cid != siginfo->si_pid)
		client_id(siginfo->si_pid);
	if (g_data.byte == 8)
	{
		ft_putchar_fd(g_data.chr, 1);
		if (g_data.chr == 0)
		{
			ft_putchar_fd('\n', 1);
			kill(siginfo->si_pid, SIGUSR1);
		}
		init_data();
		return ;
	}
	if (signal == SIGUSR1)
		g_data.chr |= (1 << g_data.byte);
	g_data.byte++;
}

int	main(void)
{
	struct sigaction	sig;

	init_data();
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
