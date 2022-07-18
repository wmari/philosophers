/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:16:36 by wmari             #+#    #+#             */
/*   Updated: 2022/07/18 12:43:16 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

struct	s_philosopher;

typedef struct	s_rules
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				notdeadyet;
	struct s_philosopher	*philosopher[100];
	pthread_mutex_t	fork[100];
	pthread_mutex_t	microphone;
	pthread_mutex_t	death;
	struct timeval	genese;
}t_rules;

typedef struct	s_philosopher
{
	int			id;
	pthread_t	philo_th_id;
	t_rules		*rules;
	struct timeval state_since_eat;
	int			nb_of_time_eat;
	
}t_philosopher;

void	*routine(void *philo);
void	fton_exit(t_rules rules);
t_rules init_rules(char **argv);
void	go_eat(t_philosopher *philo);
void	sleep_and_repeat(t_philosopher *philo);
void	print_str(char *str, t_philosopher *philo);
void	is_it_dead(t_philosopher *philo);
int		check_death(t_philosopher *philo);

#endif
