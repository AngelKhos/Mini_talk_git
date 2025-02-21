/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:47:19 by authomas          #+#    #+#             */
/*   Updated: 2025/02/19 21:18:02 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
	int pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	//receive signal
	//print the signal
	return (0);
}
