/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:45:12 by pantigon          #+#    #+#             */
/*   Updated: 2021/09/22 14:33:18 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"


int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("server id: ", 1);
	ft_putnbr_fd(pid, 1);
	while (1)
		sleep(1);
	return (1);
}