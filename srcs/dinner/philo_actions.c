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
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, "has taken a fork");
}

void	pick_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	pick_right_fork(philo);
	pick_left_fork(philo);
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_sleep(philo->conditions->time_to_eat, philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->meal_mutex);
	return ;
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_sleep(philo->conditions->time_to_sleep, philo);
	return ;
}

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking");
	return ;
}
