/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:33:37 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/06 14:57:11 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	unsigned int	num;

	i = 0;
	neg = 0;
	num = 0;
	while ((str[i] == '\n') || (str[i] == '\v') || (str[i] == '\f')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
		num = (num * 10) + str[i++] - 48;
	if ((num > 2147483647) && (!neg))
		return (-1);
	else if ((num > 2147483648) && (neg))
		return (0);
	else if (neg)
		num = ((int) num) * -1;
	return (num);
}

static int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

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

static void	send_char(char c, int pid)
{
	int	j;
	int	shift;

	j = 8;
	shift = 1;
	shift = shift << 7;
	while (j-- > 0)
	{
		if (c & shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		shift = shift >> 1;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
	if (is_valid_pid(argv[1]))
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_char(argv[2][i], pid);
			i++;
		}
		send_char('\n', pid);
	}
	return (0);
}
