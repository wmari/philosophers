/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:09:07 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 19:14:49 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	print_str_death(char *str, t_philosopher *philo)
{
	struct timeval	watch;
	long int		time;

	pthread_mutex_lock(&(philo->rules->genese.watch));
	pthread_mutex_lock(&(philo->rules->microphone));
	gettimeofday(&watch, NULL);
	time = ((watch.tv_sec * 1000000) + watch.tv_usec)
		- ((philo->rules->genese.time.tv_sec * 1000000)
			+ philo->rules->genese.time.tv_usec);
	printf("%ld\t%d\t%s\n", time, philo->id, str);
	pthread_mutex_unlock(&(philo->rules->microphone));
	pthread_mutex_unlock(&(philo->rules->genese.watch));
	return (0);
}

int	print_str(char *str, t_philosopher *philo)
{
	struct timeval	watch;
	long int		time;

	pthread_mutex_lock(&(philo->rules->genese.watch));
	gettimeofday(&watch, NULL);
	time = ((watch.tv_sec * 1000000) + watch.tv_usec)
		- ((philo->rules->genese.time.tv_sec * 1000000)
			+ philo->rules->genese.time.tv_usec);
	pthread_mutex_lock(&(philo->rules->microphone));
	if (deadyet(philo))
	{
		pthread_mutex_unlock(&(philo->rules->microphone));
		pthread_mutex_unlock(&(philo->rules->genese.watch));
		return (1);
	}
	printf("%ld\t%d\t%s\n", time, philo->id, str);
	pthread_mutex_unlock(&(philo->rules->genese.watch));
	pthread_mutex_unlock(&(philo->rules->microphone));
	return (0);
}
