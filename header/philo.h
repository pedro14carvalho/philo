/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:37:13 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/08 11:37:15 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

// **** Structs **** //

typedef struct s_conditions	t_conditions;

typedef struct s_philo
{
	int				id;
	int				meal_counter;
	size_t			last_meal_time;
	pthread_t		philo_thread_id;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_conditions	*conditions;
}		t_philo;

typedef struct s_conditions
{
	bool			simulation_ended;
	int				num_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meal_target;
	size_t			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;				// used to lock the whole structure
}		t_conditions;

// **** Init **** //

// set_conditions.c
bool			set_conditions(t_conditions *conditions, int ac, char **av);
// philo_init.c
bool			philo_init(t_philo **philo, t_conditions *conditions);

// **** Utilities **** //

// utils.c
size_t			get_current_time(void);
void			ft_sleep(long time_to_sleep, t_philo *philo);
bool			validate_args(int ac, char **av);
// simulation_utils.c
void			end_simulation(t_philo *philo);
bool			is_philosopher_full(t_philo *philo);
bool			check_death(t_philo *philo);
bool			is_simulation_running(t_philo *philo);
// print_utils.c
void			print_status(t_philo *philo, long time, char *message);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(long nb);
// char_utils.c
long			ft_atol(char *str);
bool			is_space(char c);
bool			is_digit(char c);

// **** Clean **** //

void			clean_all(t_philo *philo, t_conditions *conditions);
void			clean_conditions(t_conditions *conditions);

// **** Dinner **** //
void			*philo_routine(void *data);
void			start_dinner(t_philo *philo, t_conditions *conditions);
void			monitor_routine(t_philo *philo, t_conditions *conditions);
void			handle_one_philosopher(t_philo *philo,\
		t_conditions *conditions);

// **** Philo Actions **** //
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);

#endif
