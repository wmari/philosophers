/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:10:33 by wmari             #+#    #+#             */
/*   Updated: 2022/07/11 13:17:51 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	fton_exit(t_rules rules)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(rules.microphone));
	while (i < rules.nb_philo)
	{
		pthread_mutex_destroy(&(rules.fork[i]));
		free(rules.philosopher[i]);
		i++;
	}
}