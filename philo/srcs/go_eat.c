/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:45:50 by wmari             #+#    #+#             */
/*   Updated: 2022/07/19 16:05:05 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	end_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->is_eating));
	philo->eating = 0;
	pthread_mutex_unlock(&(philo->is_eating));	
}

static void	start_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->is_eating));
	philo->eating = 1;
	pthread_mutex_unlock(&(philo->is_eating));
}

static void	go_eat_odd(t_philosopher *philo)
{
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_lock(&(philo->rules->fork[philo->id + 1]));
	else
		pthread_mutex_lock(&(philo->rules->fork[0]));
	print_str("has taken a fork", philo);
	pthread_mutex_lock(&(philo->rules->fork[philo->id]));
	print_str("has taken a fork", philo);
	start_eat(philo);
	print_str("is eating", philo);
	my_sleep(philo->rules->time_to_eat);
}

static void	go_eat_even(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->rules->fork[philo->id]));
	print_str("has taken a fork", philo);
	if (philo->id + 1 < philo->rules->nb_philo)
		pthread_mutex_lock(&(philo->rules->fork[philo->id + 1]));
	else if (philo->id != 0)
		pthread_mutex_lock(&(philo->rules->fork[0]));
	else
		return ;
	print_str("has taken a fork", philo);
	start_eat(philo);
	print_str("is eating", philo);
	my_sleep(philo->rules->time_to_eat);
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
	pthread_mutex_lock(&(philo->is_born));
	gettimeofday(&(philo->birth), NULL);
	pthread_mutex_unlock(&(philo->is_born));
	end_eat(philo);
	if (!deadyet(philo))
		go_sleep(philo);
}
