/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:45:12 by pantigon          #+#    #+#             */
/*   Updated: 2021/09/21 20:54:23 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("server: %d\n", pid);
	while (1)
		sleep(1);
	return (1);
}