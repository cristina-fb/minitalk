/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:33:37 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/06 12:22:33 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_code	g_code;

void	ft_putnbr(int nb)
{
	unsigned int	nbr;
	char			z;

	if (nb < 0)
	{
		z = '-';
		write(1, &z, 1);
		nb = nb * (-1);
	}
	nbr = (unsigned int) nb;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		z = '0' + (nbr % 10);
		write(1, &z, 1);
	}
	else
	{
		z = '0' + nbr;
		write(1, &z, 1);
	}
}

void	handler_1(int sig)
{
	g_code.code = g_code.code << 1;
	g_code.code++;
	g_code.n_bits++;
}

void	handler_0(int sig)
{
	g_code.code = g_code.code << 1;
	g_code.n_bits++;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	bit0;
	struct sigaction	bit1;

	g_code.code = 0;
	g_code.n_bits = 0;
	bit0.sa_handler = &handler_0;
	bit0.sa_flags = 0;
	bit1.sa_handler = &handler_1;
	bit1.sa_flags = 0;
	pid = getpid();
	write(1, "El pid del servidor es: ", 24);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR2, &bit0, NULL);
	sigaction(SIGUSR1, &bit1, NULL);
	while (1)
	{
		pause();
		if (g_code.n_bits == 8)
		{
			write(1, &g_code.code, 1);
			g_code.n_bits = 0;
			g_code.code = 0;
		}
	}
}
