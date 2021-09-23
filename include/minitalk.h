/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:45:42 by pantigon          #+#    #+#             */
/*   Updated: 2021/09/23 18:59:34 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft.h"
# include <stdio.h>

typedef struct s_data
{
	int		byte;
	char	chr;
	pid_t	cid;
}	t_data;

#endif