/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:33:37 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/30 15:53:25 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	write(1, "El pid del servidor es: ", 24);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sleep(10);
}
