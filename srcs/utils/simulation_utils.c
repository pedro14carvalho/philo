/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:00:19 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/20 17:00:20 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	end_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->conditions->lock);
	philo->conditions->simulation_ended = true;
	pthread_mutex_unlock(&philo->conditions->lock);
	return ;
}

bool	is_simulation_running(t_philo *philo)
{
	bool	sim_ended;

	pthread_mutex_lock(&philo->conditions->lock);
	sim_ended = philo->conditions->simulation_ended;
	pthread_mutex_unlock(&philo->conditions->lock);
	if (sim_ended)
		return (false);
	else
		return (true);
}

bool	check_death(t_philo *philo)
{
	long	time_since_last_meal;
	size_t	timestamp;

	timestamp = get_current_time() - philo->conditions->start_time;
	pthread_mutex_lock(&philo->meal_mutex);
	time_since_last_meal = get_current_time() - philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (time_since_last_meal >= philo->conditions->time_to_die)
	{
		print_status(philo, timestamp, "died");
		end_simulation(philo);
		return (true);
	}
	else
		return (false);
}

bool	is_philosopher_full(t_philo *philo)
{
	if (philo->meal_counter == philo->conditions->meal_target)
		return (true);
	else
		return (false);
}
