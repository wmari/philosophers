/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:55:53 by wmari             #+#    #+#             */
/*   Updated: 2022/07/11 16:43:54 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *philo)
{
	t_philosopher *phil;

	phil = (t_philosopher*)philo;
	print_str("is thinking", phil);
	go_eat(phil);
	return (NULL);
}