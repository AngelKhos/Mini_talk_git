/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:47:19 by authomas          #+#    #+#             */
/*   Updated: 2025/02/27 07:33:33 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	make_len(int signal, int *call_count, int *step_counter)
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
		*call_count = 0;
		*step_counter = 1;
		return (len);
		len = 0;
	}
	return (0);
}

void	make_str(int signal, int *call_count, unsigned char *str)
{
	static unsigned char c = 0;
	static int i = 0;

	if (signal == SIGUSR1)
		c = c | 0x01 << *call_count;
	else
		c = c | 0x00 << *call_count;
	(*call_count)++;
	if (*call_count == 8)
	{
		str[i] = c;
		i++;
		*call_count = 0;
		ft_printf("char received = %c\n", c);
		c = 0;
	}
}

void	ft_handle_signal(int signal)
{
	static int call_count = 0;
	static int	step_counter = 0;
	static unsigned char *str = NULL;
	static int len = 0;

	if (step_counter == 0)
		len = make_len(signal, &call_count, &step_counter);
	if (step_counter == 1)
	{
		str = ft_calloc(sizeof(unsigned char), len + 1);
		step_counter = 2;
	}
	if (step_counter == 2)
	{
		make_str(signal, &call_count, str);
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
