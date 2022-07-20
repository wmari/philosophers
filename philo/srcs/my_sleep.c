/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:59:42 by wmari             #+#    #+#             */
/*   Updated: 2022/07/20 19:10:28 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	my_sleep(int time_to_do)
{
	struct timeval	time_begin;
	struct timeval	time_end;
	long int		time_b;
	long int		time_e;

	gettimeofday(&time_begin, NULL);
	time_end = time_begin;
	time_b = time_begin.tv_sec * 1000 + time_begin.tv_usec / 1000;
	time_e = time_end.tv_sec * 1000 + time_end.tv_usec / 1000;
	while (time_e < time_b + time_to_do)
	{
		gettimeofday(&time_end, NULL);
		time_e = time_end.tv_sec * 1000 + time_end.tv_usec / 1000;
		usleep(100);
	}
}
