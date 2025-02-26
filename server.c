/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:47:19 by authomas          #+#    #+#             */
/*   Updated: 2025/02/26 12:24:24 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	make_len(int signal, int *call_count, char **str, int *received_len)
{
	static int len = 0;

	if (signal == SIGUSR1)
		len = len | 0x01 << *call_count;
	else
		len = len | 0x00 << *call_count;
	(*call_count)++;
	if (*call_count == 32)
	{
		ft_printf("\n%d\n", len);
		*str = ft_calloc(sizeof(char), len);
		*call_count = 0;
		*received_len = 1;
		len = 0;
	}
}

void	ft_handle_signal(int signal)
{
	static int call_count = 0;
	static int	received_len = 0;
	static char *str = NULL;

	if (!received_len)
		make_len(signal, &call_count, &str, &received_len);
	else 
	{
		if (signal == SIGUSR1)
			ft_printf("1");
		else
			ft_printf("0");
	}
}
// i need to decode my characters and put it in my malloced string
// then i need to print this string
//then i may look into the bonuses

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
