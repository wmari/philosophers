/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:05:42 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 12:36:00 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	is_it_dead(t_philosopher *philo)
{
	struct timeval time_now;
	long int	time_since_eat;
	long int	time_usec;

	gettimeofday(&time_now, NULL);
	time_since_eat = (philo->state_since_eat.tv_sec * 1000000) + philo->state_since_eat.tv_usec;
	time_usec = (time_now.tv_sec * 1000000) + time_now.tv_usec;
	pthread_mutex_lock(&(philo->rules->death));
	if (time_since_eat - time_usec + (long int)philo->rules->time_to_die < 0 && philo->rules->notdeadyet == 0)
		philo->rules->notdeadyet = 1;
	pthread_mutex_unlock(&(philo->rules->death));
}

int	check_death(t_philosopher *philo)
{
	is_it_dead(philo);
	pthread_mutex_lock(&(philo->rules->death));
	if (philo->rules->notdeadyet == 1)
	{
		pthread_mutex_unlock(&(philo->rules->death));
		print_str("is dead", philo);
		return (1);
	}
	pthread_mutex_unlock(&(philo->rules->death));
	return (0);
}