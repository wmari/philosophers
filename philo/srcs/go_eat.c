/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:56:04 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 12:29:23 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	go_eat_even(t_philosopher *philo)
{
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_lock(&(philo->rules->fork[philo->id + 1]));
	else
		pthread_mutex_lock(&(philo->rules->fork[0]));
	pthread_mutex_lock(&(philo->rules->fork[philo->id]));
	print_str("is eating", philo);
	usleep(philo->rules->time_to_eat);
	gettimeofday(&(philo->state_since_eat), NULL);
	pthread_mutex_unlock(&(philo->rules->fork[philo->id]));
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_unlock(&(philo->rules->fork[philo->id + 1]));
	else
		pthread_mutex_unlock(&(philo->rules->fork[0]));
	if (!check_death(philo))
		sleep_and_repeat(philo);
}

static void	go_eat_odd(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->rules->fork[philo->id]));
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_lock(&(philo->rules->fork[philo->id + 1]));
	else
		pthread_mutex_lock(&(philo->rules->fork[0]));
	print_str("is eating", philo);
	usleep(philo->rules->time_to_eat);
	gettimeofday(&(philo->state_since_eat), NULL);
	pthread_mutex_unlock(&(philo->rules->fork[philo->id]));
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_unlock(&(philo->rules->fork[philo->id + 1]));
	else
		pthread_mutex_unlock(&(philo->rules->fork[0]));
	if (!check_death(philo))
		sleep_and_repeat(philo);
}

void	go_eat(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
		go_eat_even(philo);
	else
		go_eat_odd(philo);
}