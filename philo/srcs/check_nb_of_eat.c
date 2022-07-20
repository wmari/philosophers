/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_of_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:49:43 by wmari             #+#    #+#             */
/*   Updated: 2022/07/20 19:10:55 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	still_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->check_eat));
	if (philo->nb_of_eat > 0)
		philo->nb_of_eat--;
	if (philo->nb_of_eat == 0)
	{
		pthread_mutex_unlock(&(philo->check_eat));
		return (1);
	}
	pthread_mutex_unlock(&(philo->check_eat));
	return (0);
}

int	done_eating(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->check_eat));
	if (philo->nb_of_eat == -1)
	{
		pthread_mutex_unlock(&(philo->check_eat));
		return (0);
	}
	if (philo->nb_of_eat == 0)
	{
		pthread_mutex_unlock(&(philo->check_eat));
		return (1);
	}
	pthread_mutex_unlock(&(philo->check_eat));
	return (0);
}

int	full_course(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		if (!done_eating(rules->philo[i]))
			return (0);
		i++;
	}
	return (1);
}
