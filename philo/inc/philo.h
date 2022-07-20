/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:38:28 by wmari             #+#    #+#             */
/*   Updated: 2022/07/20 19:06:44 by wmari            ###   ########.fr       */
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

typedef struct s_death
{
	int				dead;
	pthread_mutex_t	death;
}t_death;

typedef struct s_watch
{
	struct timeval	time;
	pthread_mutex_t	watch;
}t_watch;

typedef struct s_rules
{
	int						nb_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						nb_of_eat;
	t_death					death;
	struct s_philosopher	*philo[1000];
	pthread_mutex_t			fork[1000];
	pthread_mutex_t			microphone;
	t_watch					genese;
}t_rules;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread_id;
	t_rules			*rules;
	int				nb_of_eat;
	pthread_mutex_t	check_eat;
	pthread_mutex_t	is_born;
	int				eating;
	struct timeval	birth;
}t_philosopher;

t_rules	*init_rules(int argc, char **argv);
void	quit_sim(t_rules *rules);
void	*start_sim(void *data);
int		print_str(char *str, t_philosopher *philo);
void	quit_philo(t_rules *rules);
int		check_death(t_philosopher *philo);
void	go_eat(t_philosopher *philo);
void	go_sleep(t_philosopher *philo);
int		deadyet(t_philosopher *philo);
int		print_str_death(char *str, t_philosopher *philo);
int		check_arg(int argc, char **argv);
int		still_eat(t_philosopher *philo);
int		done_eating(t_philosopher *philo);
int		full_course(t_rules *rules);
int		ft_atoi(const char *str);
void	my_sleep(int time_to_do);
void	ft_put_all(t_philosopher *philo, char *str);
void	leave_fork_right(t_philosopher *philo);
void	leave_fork_left(t_philosopher *philo);
void	take_fork_right(t_philosopher *philo);
void	take_fork_left(t_philosopher *philo);
void	ft_put_nbr(int nbr);
void	ft_put_lnbr(long int nbr);
void	ft_put_str(char *str);
#endif