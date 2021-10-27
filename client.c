/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elman <elman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:35:16 by elman             #+#    #+#             */
/*   Updated: 2021/10/27 20:41:28 by elman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_sig(int pid, int sig)
{
	if ((kill(pid, sig)) == -1)
	{
		write (1, "Signal couldn't be sent\n", 24);
		exit (0);
	}
}

void	ft_check_sig(int pid, char ch)
{
	int	i;

	i = 128;
	while (i)
	{
		if (i & ch)
			ft_send_sig(pid, SIGUSR1);
		else
			ft_send_sig(pid, SIGUSR2);
		i >>= 1;
		usleep(150);
	}
}

int	ft_number(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		write(1, "Enter correct parametrs [PID][message]\n", 39);
		exit(0);
	}
	if (!(ft_number(argv[1])))
	{
		write(1, "PID should contain only numbers\n", 32);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	while (*(argv[2]))
		ft_check_sig(pid, *(argv[2]++));
	ft_check_sig(pid, 10);
}
