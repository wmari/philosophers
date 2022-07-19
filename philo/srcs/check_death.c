/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:15:57 by wmari             #+#    #+#             */
/*   Updated: 2022/07/19 17:55:21 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	deadyet(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->rules->death.death));
	if (philo->rules->death.dead == 1)
	{
		pthread_mutex_unlock(&(philo->rules->death.death));
		return (1);
	}
	pthread_mutex_unlock(&(philo->rules->death.death));
	return (0);
}

int	check_death(t_philosopher *philo)
{
	struct timeval	time_now;
	long int		time_ms;
	long int		time_genese;
	long int		time_since_meal;

	if (deadyet(philo))
		return (1);
	gettimeofday(&time_now, NULL);
	time_ms = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	pthread_mutex_lock(&(philo->is_born));
	time_genese = (philo->birth.tv_sec * 1000) + (philo->birth.tv_usec / 1000);
	pthread_mutex_unlock(&(philo->is_born));
	time_since_meal = time_ms - time_genese;
	if (time_since_meal > philo->rules->time_to_die)
	{
		pthread_mutex_lock(&(philo->rules->death.death));
		if (philo->rules->death.dead == 0)
		{
			philo->rules->death.dead = 1;
			pthread_mutex_unlock(&(philo->rules->death.death));
			print_str_death("is dead", philo);
		}
		else
			pthread_mutex_unlock(&(philo->rules->death.death));
		return (1);
	}
	return (0);
}
