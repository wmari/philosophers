/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:31:43 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 19:16:49 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	invalid_argc(int argc)
{
	if (argc == 5 || argc == 6)
		return (0);
	printf("Error, wrong number of arguments\n");
	return (1);
}

static int	invalid_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error, arguments not valid\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_arg(int argc, char **argv)
{
	return (invalid_argc(argc) || invalid_argv(argv));
}
