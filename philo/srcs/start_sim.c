/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:03:21 by wmari             #+#    #+#             */
/*   Updated: 2022/07/19 19:24:29 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*start_sim(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	pthread_mutex_lock(&(philo->is_born));
	if (philo->id % 2)
		my_sleep(10);
	print_str("is thinking", philo);
	gettimeofday(&(philo->birth), NULL);
	pthread_mutex_unlock(&(philo->is_born));
	while (!deadyet(philo))
	{
		go_eat(philo);
		if (done_eating(philo))
			break ;
		go_sleep(philo);
	}
	return (NULL);
}
