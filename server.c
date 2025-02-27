/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:47:19 by authomas          #+#    #+#             */
/*   Updated: 2025/02/27 16:26:12 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	make_len(int signal, int *call_count, int *step_counter, int *len)
{
	if (signal == SIGUSR1)
		*len = *len | 1 << *call_count;
	else
		*len = *len | 0 << *call_count;
	(*call_count)++;
	if (*call_count == 32)
	{
		*call_count = 0;
		*step_counter = 1;
	}
}

void	make_str(int signal, int *call_count, unsigned char *str, int len)
{
	static unsigned char	c = 0;
	static int				i = 0;

	if (signal == SIGUSR1)
		c = c | 1 << *call_count;
	else
		c = c | 0 << *call_count;
	(*call_count)++;
	if (*call_count == 8)
	{
		str[i] = c;
		i++;
		*call_count = 0;
		c = 0;
		if (i == len)
			i = 0;
	}
}

void	ft_print_n_clean(unsigned char **str, int *step_counter, int *len)
{
	write (1, *str, *len);
	write (1, "\n", 1);
	free(*str);
	*str = NULL;
	*step_counter = 0;
	*len = 0;
}

void	ft_handle_signal(int signal)
{
	static int				call_count = 0;
	static int				step_counter = 0;
	static unsigned char	*str = NULL;
	static int				len = 0;

	if (step_counter == 1)
	{
		if (len != 0)
		{
			str = ft_calloc(sizeof(unsigned char), len + 1);
			if (!str)
				exit(EXIT_FAILURE);
			step_counter = 2;
		}
		else
			step_counter = 0;
	}
	if (step_counter == 2)
	{
		make_str(signal, &call_count, str, len);
		if (str[len - 1])
			ft_print_n_clean(&str, &step_counter, &len);
	}
	else if (step_counter == 0)
		make_len(signal, &call_count, &step_counter, &len);
}

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
