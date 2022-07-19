/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:46:09 by wmari             #+#    #+#             */
/*   Updated: 2022/07/19 15:51:28 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int check_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->is_eating));
	if (philo->eating == 1)
	{
		pthread_mutex_unlock(&(philo->is_eating));
		return (0);
	}
	pthread_mutex_unlock(&(philo->is_eating));
	return (1);
}

static void	deathloop(t_rules *rules)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < rules->nb_philo)
		{
			if (check_eat(rules->philo[i]))
			{
				if (check_death(rules->philo[i]))
					break ;
			}
			i++;
		}
		if (deadyet(rules->philo[0]) || full_course(rules))
			break ;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	t_rules	*rules;
	int		i;

	if (check_arg(argc, argv))
		return (0);
	i = 0;
	rules = init_rules(argc, argv);
	gettimeofday(&(rules->genese.time), NULL);
	while (i < rules->nb_philo)
	{
		rules->philo[i]->rules = rules;
		pthread_create(&(rules->philo[i]->thread_id), NULL,
			start_sim, rules->philo[i]);
		i++;
	}
	my_sleep(2);
	deathloop(rules);
	i = 0;
	while (i < rules->nb_philo)
		pthread_join(rules->philo[i++]->thread_id, NULL);
	quit_philo(rules);
}
