/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:33:37 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/06 12:24:11 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_valid_pid(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	j;
	int	shift;

	if (argc != 3)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
	if (is_valid_pid(argv[1]))
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			j = 8;
			shift = 1;
			shift = shift << 7;
			while (j-- > 0)
			{
				if (argv[2][i] & shift)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				shift = shift >> 1;
				usleep(50);
			}
			i++;
		}
	}
	return (0);
}
