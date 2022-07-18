/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:27:40 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 12:44:42 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_rules init_rules(char **argv)
{
	t_rules rules;
	int		i;
	
	rules.nb_philo = atoi(argv[1]);
	rules.time_to_die = atoi(argv[2]);
	rules.time_to_eat = atoi(argv[3]);
	rules.time_to_sleep = atoi(argv[4]);
	rules.notdeadyet = 0;
	pthread_mutex_init(&(rules.death), NULL);
	i = 0;
	while (i < 100)
	{
		if (i < rules.nb_philo)
		{
			rules.philosopher[i] = malloc(sizeof(t_philosopher));
			rules.philosopher[i]->id = i;
			pthread_mutex_init(&(rules.fork[i]), NULL);
			rules.philosopher[i]->state_since_eat.tv_usec = (long int)rules.time_to_die;
		}
		else
			rules.philosopher[i] = NULL;
		i++;
	}
	pthread_mutex_init(&(rules.microphone), NULL);
	gettimeofday(&rules.genese, NULL);
	return (rules);
}