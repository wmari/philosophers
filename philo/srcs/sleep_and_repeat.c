/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_repeat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:56:35 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 12:28:30 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	sleep_and_repeat(t_philosopher *philo)
{
	print_str("is sleeping", philo);
	usleep(philo->rules->time_to_sleep);
	if (!check_death(philo))
	{
		print_str("is thinking", philo);
		if (!check_death(philo))
			go_eat(philo);
	}
}