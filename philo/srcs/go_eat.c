/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:56:04 by wmari             #+#    #+#             */
/*   Updated: 2022/07/11 16:45:37 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	go_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->rules->fork[philo->id]));
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_lock(&(philo->rules->fork[philo->id + 1]));
	else
		pthread_mutex_lock(&(philo->rules->fork[0]));
	print_str("is eating", philo);
	usleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(&(philo->rules->fork[philo->id]));
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_unlock(&(philo->rules->fork[philo->id + 1]));
	else
		pthread_mutex_unlock(&(philo->rules->fork[0]));
	sleep_and_repeat(philo);
}