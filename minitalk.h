#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
//color
# define BLUE "\e[1;34m"  

typedef struct s_data
{
	int		th_char;
	int		cnt_bit;
}	t_data;

//func
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi (char *str);
int		ft_isdigit(int c);
#endif