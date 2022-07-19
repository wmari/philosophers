/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:09:07 by wmari             #+#    #+#             */
/*   Updated: 2022/07/19 17:43:52 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	print_str_death(char *str, t_philosopher *philo)
{
	struct timeval	watch;
	long int		time;

	pthread_mutex_lock(&(philo->rules->microphone));
	gettimeofday(&watch, NULL);
	time = ((watch.tv_sec * 1000) + watch.tv_usec / 1000)
		- ((philo->rules->genese.time.tv_sec * 1000)
			+ philo->rules->genese.time.tv_usec / 1000);
	ft_put_all(time, philo->id, str);
	pthread_mutex_unlock(&(philo->rules->microphone));
	return (0);
}

int	print_str(char *str, t_philosopher *philo)
{
	struct timeval	watch;
	long int		time;
	long int		time_phil;

	if (deadyet(philo))
		return (1);
	pthread_mutex_lock(&(philo->rules->microphone));
	gettimeofday(&watch, NULL);
	time_phil = ((philo->rules->genese.time.tv_sec * 1000)
			+ philo->rules->genese.time.tv_usec / 1000);
	time = ((watch.tv_sec * 1000) + watch.tv_usec / 1000) - time_phil;
	ft_put_all(time, philo->id, str);
	pthread_mutex_unlock(&(philo->rules->microphone));
	return (0);
}
