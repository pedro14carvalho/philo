/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:37:50 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/08 11:37:52 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static bool	init_philo_params(t_philo **philo, t_conditions *conditions)
{
	int	i;
	int	num_of_philos;

	num_of_philos = conditions->num_of_philos;
	i = 0;
	while (i < num_of_philos)
	{
		(*philo)[i].id = (i + 1);
		(*philo)[i].meal_counter = 0;
		(*philo)[i].last_meal_time = (long)conditions->start_time;
		(*philo)[i].r_fork = &conditions->forks[i];
		(*philo)[i].l_fork = &conditions->forks[(i + 1) % num_of_philos];
		(*philo)[i].conditions = conditions;
		if (pthread_mutex_init(&(*philo)[i].meal_mutex, NULL) != 0)
		{
			ft_putstr("error: not enough memory\n");
			while (--i >= 0)
				pthread_mutex_destroy(&(*philo)[i].meal_mutex);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	philo_init(t_philo **philo, t_conditions *conditions)
{
	int	num_of_philos;

	num_of_philos = conditions->num_of_philos;
	*philo = malloc(sizeof(t_philo) * num_of_philos);
	if (!*philo)
	{
		ft_putstr("error: not enough memory\n");
		return (false);
	}
	if (init_philo_params(philo, conditions) == false)
	{
		free(*philo);
		return (false);
	}
	return (true);
}
