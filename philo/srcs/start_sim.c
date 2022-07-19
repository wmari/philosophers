/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:03:21 by wmari             #+#    #+#             */
/*   Updated: 2022/07/19 16:24:00 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*start_sim(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	pthread_mutex_lock(&(philo->is_born));
	if (philo->id % 2)
		my_sleep(20);
	print_str("is thinking", philo);
	gettimeofday(&(philo->birth), NULL);
	pthread_mutex_unlock(&(philo->is_born));
	if (!check_death(philo))
		go_eat(philo);
	return (NULL);
}
