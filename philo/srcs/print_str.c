/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:02:21 by wmari             #+#    #+#             */
/*   Updated: 2022/07/11 16:50:25 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_str(char *str, t_philosopher *philo)
{
	struct timeval time_now;

	pthread_mutex_lock(&(philo->rules->watches));
	gettimeofday(&time_now, NULL);
	pthread_mutex_lock(&(philo->rules->microphone));
	printf("%ld %d %s \n", (time_now.tv_usec - philo->genese.tv_usec), philo->id, str);
	pthread_mutex_unlock(&(philo->rules->watches));
	pthread_mutex_unlock(&(philo->rules->microphone));	
}
