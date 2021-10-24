
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