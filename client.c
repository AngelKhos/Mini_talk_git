/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:09:47 by authomas          #+#    #+#             */
/*   Updated: 2025/02/23 15:35:03 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	handle_error(int ac, char **av)
{
	int	i;

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
	return (0);
}

static void	send_len(int len, int pid)
{
	int	i;

	i = 0;
	ft_printf("len = %d\n", len);
	while (i < 32)
	{
		if (len % 2)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		len = len >> 1;
		usleep (50);
		i++;
	}
}

static void	send_char(int c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		c = c >> 1;
		usleep (50);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;

	if (handle_error(ac, av) == -1)
		return (-1);
	i = 0;
	pid = ft_atoi(av[1]);
	send_len(ft_strlen(av[2]), pid);
	while (av[2][i])
	{
		send_char(av[2][i], pid);
		i++;
	}
	return (0);
}
