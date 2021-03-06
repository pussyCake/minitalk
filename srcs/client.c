
#include "minitalk.h"

int	error_msg(char *msg)
{
	if (msg)
		write(1, msg, ft_strlen(msg));
	exit(0);
}

void	change_signal(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("server [", 1);
		ft_putnbr_fd(siginfo->si_pid, 1);
		ft_putstr_fd("]: done\n", 1);
		exit(0);
	}
}

void	sent_msg(int pid, char *msg)
{
	int	n;

	while (*msg || *msg == '\0')
	{
		n = 0;
		while (n < 9)
		{
			if (((*msg >> n) & 1) > 0)
			{
				if (kill(pid, SIGUSR1) != 0)
					error_msg("PID incorrect\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) != 0)
					error_msg("PID incorrect\n");
			}
			usleep(100);
			++n;
		}
		if (*msg == '\0')
			return ;
		msg++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sig;
	pid_t				pid;

	if (ac != 3)
		error_msg("ERROR: client request fail!!\n");
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		error_msg("PID incorrect\n");
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = change_signal;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	sent_msg(pid, av[2]);
	while (1)
		pause();
	return (1);
}
