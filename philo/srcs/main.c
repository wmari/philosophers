/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:37:29 by wmari             #+#    #+#             */
/*   Updated: 2022/07/11 16:51:33 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"



int	main(int argc, char **argv)
{
	t_rules	rules;
	int i;

	(void)argc;
	i = 0;
	rules = init_rules(argv);
	while (i < rules.nb_philo)
	{
		rules.philosopher[i]->rules = &rules;
		pthread_create(&(rules.philosopher[i]->philo_th_id), NULL, routine, rules.philosopher[i]);
		i++;
	}
	i = 0;
	while (i < rules.nb_philo)
		pthread_join(rules.philosopher[i++]->philo_th_id, NULL);
	fton_exit(rules);
}