/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:33:37 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/30 15:50:33 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	printf("-%d-", pid);
	return (0);
}
