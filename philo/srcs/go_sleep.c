/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:58:14 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 19:13:17 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	go_sleep(t_philosopher *philo)
{
	print_str("is sleeping", philo);
	usleep(philo->rules->time_to_sleep);
	if (!deadyet(philo))
	{
		print_str("is thinking", philo);
		if (!deadyet(philo))
			go_eat(philo);
	}
}