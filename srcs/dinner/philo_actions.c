/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:39:46 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/08 11:39:47 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	pick_right_fork(t_philo *philo)
{
	size_t	time;
	size_t	timestamp;

	pthread_mutex_lock(philo->r_fork);
	timestamp = get_current_time();
	time = timestamp - philo->conditions->start_time;
	print_status(philo, time, "has taken a fork");
}

void	pick_left_fork(t_philo *philo)
{
	size_t	time;
	size_t	timestamp;

	pthread_mutex_lock(philo->l_fork);
	timestamp = get_current_time();
	time = timestamp - philo->conditions->start_time;
	print_status(philo, time, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	size_t	time;
	size_t	timestamp;

	if (philo->l_fork < philo->r_fork)
	{
		pick_left_fork(philo);
		pick_right_fork(philo);
	}
	else
	{
		pick_right_fork(philo);
		pick_left_fork(philo);
	}
	timestamp = get_current_time();
	time = timestamp - philo->conditions->start_time;
	print_status(philo, time, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	// last_meal_time previously updated here. changed to see if anything would change
	usleep(philo->conditions->time_to_eat * 1000);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	philo->last_meal_time = get_current_time();
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->meal_mutex);
	return ;
}

void	philo_sleep(t_philo *philo)
{
	size_t	time;
	size_t	timestamp;

	timestamp = get_current_time();
	time = timestamp - philo->conditions->start_time;
	print_status(philo, time, "is sleeping");
	ft_sleep(philo->conditions->time_to_sleep, philo);
	return ;
}

void	philo_think(t_philo *philo)
{
	size_t	time;
	size_t	timestamp;

	timestamp = get_current_time();
	time = timestamp - philo->conditions->start_time;
	print_status(philo, time, "is thinking");
	return ;
}
