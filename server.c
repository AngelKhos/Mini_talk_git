/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:47:19 by authomas          #+#    #+#             */
/*   Updated: 2025/02/23 15:11:53 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	ft_handle_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("1");
	else
		ft_printf("0");
}
// void set_signal(void)
// {
	
// }

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID server : %d\n", pid);
	signal(SIGUSR1, ft_handle_signal);
	signal(SIGUSR2, ft_handle_signal);
	while (1)
		;
	return (0);
}
