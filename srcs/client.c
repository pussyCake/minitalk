/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:45:16 by pantigon          #+#    #+#             */
/*   Updated: 2021/09/21 20:54:22 by pantigon         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	if (ac != 3)
		return (error_msg("ERROR: client request fail!!\n"));
	
	return (1);
}