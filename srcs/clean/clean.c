/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:37:27 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/08 11:37:29 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static void	clean_philo(t_philo *philo, t_conditions *conditions)
{
	int	i;
	int	num_of_philos;

	i = 0;
	num_of_philos = conditions->num_of_philos;
	while (i < num_of_philos)
	{
		pthread_mutex_destroy(&philo[i].meal_mutex);
		i++;
	}
	free(philo);
	philo = NULL;
}

void	clean_conditions(t_conditions *conditions)
{
	int	i;
	int	num_of_philos;

	i = 0;
	num_of_philos = conditions->num_of_philos;
	if (conditions->forks)
	{
		while (i < num_of_philos)
		{
			pthread_mutex_destroy(&conditions->forks[i]);
			i++;
		}
		free(conditions->forks);
		conditions->forks = NULL;
	}
	pthread_mutex_destroy(&conditions->lock);
	return ;
}

void	clean_all(t_philo *philo, t_conditions *conditions)
{
	clean_philo(philo, conditions);
	clean_conditions(conditions);
}
