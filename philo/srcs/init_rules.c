/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:46:52 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 19:20:36 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	init_phil(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo && i < 1000)
	{
		rules->philo[i] = malloc(sizeof(t_philosopher));
		rules->philo[i]->id = i;
		rules->philo[i]->nb_of_eat = rules->nb_of_eat;
		pthread_mutex_init(&(rules->fork[i]), NULL);
		i++;
	}
	while (i < 1000)
		rules->philo[i++] = NULL;
}

t_rules	*init_rules(int argc, char **argv)
{
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	rules->nb_philo = atoi(argv[1]);
	rules->time_to_die = atoi(argv[2]);
	rules->time_to_eat = atoi(argv[3]);
	rules->time_to_sleep = atoi(argv[4]);
	if (argc == 5)
		rules->nb_of_eat = -1;
	else
		rules->nb_of_eat = atoi(argv[5]);
	init_phil(rules);
	pthread_mutex_init(&(rules->microphone), NULL);
	pthread_mutex_init(&(rules->death.death), NULL);
	rules->death.dead = 0;
	return (rules);
}
