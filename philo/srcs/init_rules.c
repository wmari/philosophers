/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:46:52 by wmari             #+#    #+#             */
/*   Updated: 2022/07/21 15:09:20 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	destroy_all_fail(t_rules *rules, int i, int nb_act)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&(rules->fork[j]));
		pthread_mutex_destroy(&(rules->philo[j]->check_eat));
		pthread_mutex_destroy(&(rules->philo[j++]->is_born));
	}
	if (nb_act >= 1)
	{
		if (nb_act == 2)
			pthread_mutex_unlock(&(rules->philo[i]->check_eat));
		pthread_mutex_unlock(&(rules->fork[i]));
	}
	j = 0;
	while (j < i)
		free(rules->philo[j++]);
	return (1);
}

static int	init_phil(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo && i < 1000)
	{
		rules->philo[i] = malloc(sizeof(t_philosopher));
		rules->philo[i]->id = i;
		rules->philo[i]->nb_of_eat = rules->nb_of_eat;
		rules->philo[i]->eating = 0;
		gettimeofday(&(rules->philo[i]->birth), NULL);
		if (pthread_mutex_init(&(rules->fork[i]), NULL) != 0)
			return (destroy_all_fail(rules, i, 0));
		if (pthread_mutex_init(&(rules->philo[i]->check_eat), NULL) != 0)
			return (destroy_all_fail(rules, i, 1));
		if (pthread_mutex_init(&(rules->philo[i]->is_born), NULL) != 0)
			return (destroy_all_fail(rules, i, 2));
		i++;
	}
	while (i < 1000)
		rules->philo[i++] = NULL;
	return (0);
}

static int	init_mutex_rules(t_rules *rules)
{
	if (pthread_mutex_init(&(rules->microphone), NULL) != 0)
	{
		destroy_all_fail(rules, rules->nb_philo, 0);
		free(rules);
		return (1);
	}
	if (pthread_mutex_init(&(rules->death.death), NULL) != 0)
	{
		destroy_all_fail(rules, rules->nb_philo, 0);
		pthread_mutex_destroy(&(rules->microphone));
		free(rules);
		return (1);
	}
	return (0);
}

t_rules	*init_rules(int argc, char **argv)
{
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		rules->nb_of_eat = -1;
	else
		rules->nb_of_eat = ft_atoi(argv[5]);
	if (init_phil(rules))
		return (NULL);
	if (init_mutex_rules(rules))
		return (NULL);
	rules->death.dead = 0;
	return (rules);
}
