/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:09:47 by authomas          #+#    #+#             */
/*   Updated: 2025/02/21 16:34:12 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_len(int len, int pid)
{
	
}
void	send_char(int c, int pid)
{
	
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*send;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Invalid argument, error");
		return (-1);
	}
	while (av[1][i])
	{
		if (!ft_strchr("0123456789", av[1][i]))
		{
			ft_printf("Invalid PID, error");
			return (-1);
		}
		i++;
	}
	pid = ft_atoi(av[1]);
	send = av[2];

	return (0);
}
