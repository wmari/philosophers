/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:46:09 by wmari             #+#    #+#             */
/*   Updated: 2022/07/22 12:25:52 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	deathloop(t_rules *rules)
{
	int	i;

	i = 0;
	while (1)
	{
		my_sleep(5);
		while (i < rules->nb_philo)
		{
			if (check_death(rules->philo[i]))
				break ;
			else
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
	if (!rules)
	{
		printf("Error, initialisation failed\n");
		return (0);
	}
	gettimeofday(&(rules->genese.time), NULL);
	while (i < rules->nb_philo)
	{
		rules->philo[i]->rules = rules;
		pthread_create(&(rules->philo[i]->thread_id), NULL,
			start_sim, rules->philo[i]);
		i++;
	}
	deathloop(rules);
	i = 0;
	while (i < rules->nb_philo)
		pthread_join(rules->philo[i++]->thread_id, NULL);
	return (quit_philo(rules));
}
