/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:37:38 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/08 11:37:39 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	handle_one_philosopher(t_philo *philo, t_conditions *conditions)
{
	print_status(philo, 0, "has taken a fork");
	usleep(conditions->time_to_die * 1000);
	print_status(philo, conditions->time_to_die, "died");
	return ;
}

void	monitor_routine(t_philo *philo, t_conditions *conditions)
{
	int	i;

	while (is_simulation_running(philo) && !are_all_philosophers_full(philo, conditions))
	{
		i = 0;
		while (i < conditions->num_of_philos)
		{
			if (!is_philosopher_full(&philo[i]))
				check_death(&philo[i]);
			i++;
		}
		usleep(1000);
	}
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (is_simulation_running(philo) && !is_philosopher_full(philo))
	{
		philo_eat(philo);
		if (!is_simulation_running(philo))
			break ;
		philo_sleep(philo);
		if (!is_simulation_running(philo))
			break ;
		philo_think(philo);
	}
	return (NULL);
}

void	start_dinner(t_philo *philo, t_conditions *conditions)
{
	int	i;

	i = 0;
	while (i < conditions->num_of_philos)
	{
		if (pthread_create(&philo[i].philo_thread_id, NULL, philo_routine, &philo[i]) != 0)
		{
			ft_putstr("error: failed to create threads\n");
			return ;
		}
		i++;
	}
	monitor_routine(philo, conditions);
	i = 0;
	while (i < conditions->num_of_philos)
	{
		pthread_join(philo[i].philo_thread_id, NULL);
		i++;
	}
	return ;
}
