/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:33:37 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/06 14:57:28 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_code	g_code;

static void	ft_putnbr(int nb)
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

void	handler(int sig)
{
	g_code.code = g_code.code << 1;
	if (sig == SIGUSR1)
		g_code.code++;
	g_code.n_bits++;
}

static void	initialize(void)
{
	int	pid;

	g_code.code = 0;
	g_code.n_bits = 0;
	pid = getpid();
	write(1, "El pid del servidor es: ", 24);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

int	main(void)
{
	struct sigaction	bit0;
	struct sigaction	bit1;

	initialize();
	bit0.sa_handler = &handler;
	bit0.sa_flags = 0;
	bit1.sa_handler = &handler;
	bit1.sa_flags = 0;
	sigaction(SIGUSR2, &bit0, NULL);
	sigaction(SIGUSR1, &bit1, NULL);
	while (1)
	{
		pause();
		if (g_code.n_bits == 8)
		{
			write(1, &g_code.code, 1);
			if (g_code.code == 0)
				write(1, "\n", 1);
			g_code.n_bits = 0;
			g_code.code = 0;
		}
	}
}
