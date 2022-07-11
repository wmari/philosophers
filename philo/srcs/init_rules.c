/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:27:40 by wmari             #+#    #+#             */
/*   Updated: 2022/07/11 19:05:07 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_rules init_rules(char **argv)
{
	t_rules rules;
	int		i;
	struct timeval time_now = {0, 0};

	gettimeofday(&time_now, NULL);
	rules.nb_philo = atoi(argv[1]);
	rules.time_to_die = atoi(argv[2]);
	rules.time_to_eat = atoi(argv[3]);
	rules.time_to_sleep = atoi(argv[4]);
	i = 0;
	pthread_mutex_init(&(rules.watches), NULL);
	while (i < 100)
	{
		if (i < rules.nb_philo)
		{
			rules.philosopher[i] = malloc(sizeof(t_philosopher));
			//rules.philosopher[i]->rules = &rules;
			rules.philosopher[i]->id = i;
			pthread_mutex_init(&(rules.fork[i]), NULL);
			rules.philosopher[i]->genese = time_now;
		}
		else
			rules.philosopher[i] = NULL;
		i++;
	}
	pthread_mutex_init(&(rules.microphone), NULL);
	return (rules);
}