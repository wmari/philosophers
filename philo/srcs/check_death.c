/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:15:57 by wmari             #+#    #+#             */
/*   Updated: 2022/07/21 14:38:38 by wmari            ###   ########.fr       */
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

long int	get_time_since_lm(t_philosopher *philo)
{
	struct timeval	time_now;
	long int		time_ms;
	long int		time_genese;

	gettimeofday(&time_now, NULL);
	time_ms = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	pthread_mutex_lock(&(philo->is_born));
	time_genese = (philo->birth.tv_sec * 1000) + (philo->birth.tv_usec / 1000);
	pthread_mutex_unlock(&(philo->is_born));
	return (time_ms - time_genese);
}

int	check_death(t_philosopher *philo)
{
	long int	time_since_meal;

	time_since_meal = get_time_since_lm(philo);
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
