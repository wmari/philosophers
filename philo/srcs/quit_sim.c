/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:04:50 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 20:07:08 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	quit_philo(t_rules *rules)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(rules->microphone));
	while (i < rules->nb_philo)
	{
		pthread_mutex_destroy(&(rules->fork[i]));
		pthread_mutex_destroy(&(rules->philo[i]->check_eat));
		free(rules->philo[i++]);
	}
	pthread_mutex_destroy(&(rules->death.death));
	free(rules);
}
