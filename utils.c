/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elman <elman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:23:32 by elman             #+#    #+#             */
/*   Updated: 2021/10/27 11:07:17 by elman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi (char *str)
{
	int				neg;
	unsigned long	nb;
	unsigned long	a;

	a = 9223372036854775807;
	neg = 1;
	nb = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
		neg = neg * -1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		nb = (nb * 10) + (*str - 48);
		str++;
		if (nb > a && neg > 0)
			return (-1);
		if (nb >= a && neg < 0)
			return (0);
	}
	return (nb * neg);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num[120];
	int		i;
	long	nb;

	nb = (long) n;
	i = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb / 10)
		ft_putnbr_fd(nb / 10, fd);
	num[i] = nb % 10 + 48;
	write(fd, &num[i++], 1);
	num[i] = '\0';
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_isdigit(int c)
{
	if (('9' >= c) && (c >= '0'))
		return (1);
	else
		return (0);
}
