/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:15:28 by wmari             #+#    #+#             */
/*   Updated: 2022/07/22 12:30:02 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_put_lnbr(long int nbr)
{
	char	c;

	if (nbr / 10 > 0)
		ft_put_lnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	ft_put_nbr(int nbr)
{
	char	c;

	if (nbr / 10 > 0)
		ft_put_nbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	put_any(long int time, int philo_id, char *str)
{
	ft_put_lnbr(time);
	write(1, "\t", 1);
	ft_put_nbr(philo_id + 1);
	write(1, "\t", 1);
	ft_put_str(str);
	write(1, "\n", 1);
}

void	ft_put_all(t_philosopher *philo, char *str)
{
	struct timeval	watch;
	long int		time;
	long int		time_phil;

	if (!deadyet(philo))
	{
		pthread_mutex_lock(&(philo->rules->microphone));
		pthread_mutex_lock(&(philo->rules->death.death));
		if (philo->rules->death.dead)
		{
			pthread_mutex_unlock(&(philo->rules->death.death));
			pthread_mutex_unlock(&(philo->rules->microphone));
			return ;
		}
		gettimeofday(&watch, NULL);
		time_phil = ((philo->rules->genese.time.tv_sec * 1000)
				+ philo->rules->genese.time.tv_usec / 1000);
		time = ((watch.tv_sec * 1000) + watch.tv_usec / 1000) - time_phil;
		put_any(time, philo->id, str);
		pthread_mutex_unlock(&(philo->rules->death.death));
		pthread_mutex_unlock(&(philo->rules->microphone));
	}
}
