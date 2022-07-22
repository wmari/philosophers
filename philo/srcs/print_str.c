/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:09:07 by wmari             #+#    #+#             */
/*   Updated: 2022/07/22 12:20:16 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	print_str_death(char *str, t_philosopher *philo)
{
	struct timeval	watch;
	long int		time;
	long int		time_phil;

	pthread_mutex_lock(&(philo->rules->microphone));
	gettimeofday(&watch, NULL);
	time_phil = ((philo->rules->genese.time.tv_sec * 1000)
			+ philo->rules->genese.time.tv_usec / 1000);
	time = ((watch.tv_sec * 1000) + watch.tv_usec / 1000) - time_phil;
	ft_put_lnbr(time);
	write(1, "\t", 1);
	ft_put_nbr(philo->id + 1);
	write(1, "\t", 1);
	ft_put_str(str);
	write(1, "\n", 1);
	pthread_mutex_unlock(&(philo->rules->microphone));
	return (0);
}

int	print_str(char *str, t_philosopher *philo)
{
	if (deadyet(philo))
		return (1);
	ft_put_all(philo, str);
	return (0);
}
