/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:03:21 by wmari             #+#    #+#             */
/*   Updated: 2022/07/20 19:52:30 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*start_sim(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	pthread_mutex_lock(&(philo->is_born));
	gettimeofday(&(philo->birth), NULL);
	if (philo->id % 2)
		my_sleep(10);
	pthread_mutex_unlock(&(philo->is_born));
	while (!deadyet(philo))
	{
		usleep(100);
		print_str("is thinking", philo);
		if (go_eat(philo))
			break ;
		if (done_eating(philo))
			break ;
		go_sleep(philo);
	}
	return (NULL);
}
