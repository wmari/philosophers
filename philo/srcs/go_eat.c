/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:45:50 by wmari             #+#    #+#             */
/*   Updated: 2022/07/20 19:42:05 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	go_eat_odd(t_philosopher *philo)
{
	take_fork_left(philo);
	take_fork_right(philo);
	print_str("is eating", philo);
	pthread_mutex_lock(&(philo->is_born));
	gettimeofday(&(philo->birth), NULL);
	pthread_mutex_unlock(&(philo->is_born));
	my_sleep(philo->rules->time_to_eat);
	leave_fork_left(philo);
	leave_fork_right(philo);
}

static void	go_eat_even(t_philosopher *philo)
{
	take_fork_right(philo);
	take_fork_left(philo);
	print_str("is eating", philo);
	pthread_mutex_lock(&(philo->is_born));
	gettimeofday(&(philo->birth), NULL);
	pthread_mutex_unlock(&(philo->is_born));
	my_sleep(philo->rules->time_to_eat);
	leave_fork_right(philo);
	leave_fork_left(philo);
}

int	go_eat(t_philosopher *philo)
{
	if (philo->id + 1 >= philo->rules->nb_philo && philo->id == 0)
	{
		take_fork_right(philo);
		my_sleep(philo->rules->time_to_die + 50);
		leave_fork_right(philo);
		return (1);
	}
	else if (philo->id % 2 == 0)
		go_eat_even(philo);
	else
		go_eat_odd(philo);
	still_eat(philo);
	return (0);
}
