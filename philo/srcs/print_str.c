/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:02:21 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 12:43:55 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_str(char *str, t_philosopher *philo)
{
	struct timeval time_now;
	long int time_used;

	gettimeofday(&time_now, NULL);
	time_used = ((time_now.tv_sec * 1000000) + time_now.tv_usec) - ((philo->rules->genese.tv_sec * 1000000) - philo->rules->genese.tv_usec);
	pthread_mutex_lock(&(philo->rules->microphone));
	printf("%ld %d %s \n", time_used, philo->id, str);
	pthread_mutex_unlock(&(philo->rules->microphone));	
}
