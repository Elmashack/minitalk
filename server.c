/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elman <elman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:35:16 by elman             #+#    #+#             */
/*   Updated: 2021/10/27 11:40:44 by elman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	signal_handler(int sig)
{	
	if (sig == SIGUSR1)
		g_data.th_char += g_data.cnt_bit;
	else if (sig == SIGUSR2)
		g_data.th_char += 0;
	g_data.cnt_bit /= 2;
	if (g_data.cnt_bit < 1)
	{
		ft_putchar_fd((unsigned char)g_data.th_char, 1);
		g_data.cnt_bit = 128;
		g_data.th_char = 0;
	}
}

int	main(void)
{
	pid_t	serv_pid;

	g_data.cnt_bit = 128;
	g_data.th_char = 0;
	serv_pid = getpid();
	write(1, "\e[1;34mSerever run: ", 20);
	ft_putnbr_fd(serv_pid, 1);
	write(1, "\e[0m\n", 5);
	while (1)
	{
		signal(SIGUSR2, signal_handler);
		signal(SIGUSR1, signal_handler);
	}	
}
