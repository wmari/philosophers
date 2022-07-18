/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:45:50 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 20:14:28 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	go_eat_odd(t_philosopher *philo)
{
	usleep(5);
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_lock(&(philo->rules->fork[philo->id + 1]));
	else
		pthread_mutex_lock(&(philo->rules->fork[0]));
	print_str("has taken a fork", philo);
	pthread_mutex_lock(&(philo->rules->fork[philo->id]));
	print_str("has taken a fork", philo);
	print_str("is eating", philo);
	usleep(philo->rules->time_to_eat);
}

static void	go_eat_even(t_philosopher *philo)
{
	usleep(5);
	pthread_mutex_lock(&(philo->rules->fork[philo->id]));
	print_str("has taken a fork", philo);
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_lock(&(philo->rules->fork[philo->id + 1]));
	else if (philo->id != 0)
		pthread_mutex_lock(&(philo->rules->fork[0]));
	else
		return ;
	print_str("has taken a fork", philo);
	print_str("is eating", philo);
	usleep(philo->rules->time_to_eat);
}

void	go_eat(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
		go_eat_even(philo);
	else
		go_eat_odd(philo);
	pthread_mutex_unlock(&(philo->rules->fork[philo->id]));
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_unlock(&(philo->rules->fork[philo->id + 1]));
	else if (philo->id != 0)
		pthread_mutex_unlock(&(philo->rules->fork[0]));
	else
		return ;
	if (still_eat(philo))
		return ;
	gettimeofday(&(philo->birth), NULL);
	if (!deadyet(philo))
		go_sleep(philo);
}
