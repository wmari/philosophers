/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:26:22 by wmari             #+#    #+#             */
/*   Updated: 2022/07/20 19:11:18 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_fork_left(t_philosopher *philo)
{
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_lock(&(philo->rules->fork[philo->id + 1]));
	else
		pthread_mutex_lock(&(philo->rules->fork[0]));
	print_str("has taken a fork", philo);
}

void	take_fork_right(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->rules->fork[philo->id]));
	print_str("has taken a fork", philo);
}

void	leave_fork_left(t_philosopher *philo)
{
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_unlock(&(philo->rules->fork[philo->id + 1]));
	else if (philo->id != 0)
		pthread_mutex_unlock(&(philo->rules->fork[0]));
}

void	leave_fork_right(t_philosopher *philo)
{
	pthread_mutex_unlock(&(philo->rules->fork[philo->id]));
}
