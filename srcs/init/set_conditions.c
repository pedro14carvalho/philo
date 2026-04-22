/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:38:00 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/08 11:38:01 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static bool	check_int_max(t_conditions *conditions)
{
	if (conditions->num_of_philos > INT_MAX
		|| conditions->time_to_die > INT_MAX
		|| conditions->time_to_eat > INT_MAX
		|| conditions->time_to_sleep > INT_MAX
		|| conditions->meal_target > INT_MAX)
	{
		ft_putstr("Number too big, has to be smaller than INT_MAX\
				(2,147,483,647)\n");
		return (false);
	}
	else
		return (true);

}

static bool	create_forks(t_conditions *conditions, int num_of_philos)
{
	int	i;

	i = 0;
	conditions->forks = malloc(num_of_philos * sizeof(pthread_mutex_t));
	if (!conditions->forks)
	{
		ft_putstr("error: not enough memory\n");
		return (false);
	}
	while (i < num_of_philos)
	{
		if (pthread_mutex_init(&conditions->forks[i], NULL) != 0)
		{
			ft_putstr("error: not enough memory\n");
			while (--i >= 0)
				pthread_mutex_destroy(&conditions->forks[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	set_conditions(t_conditions *conditions, int ac, char **av)
{
	conditions->num_of_philos = ft_atol(av[1]);
	conditions->time_to_die = ft_atol(av[2]);
	conditions->time_to_eat = ft_atol(av[3]);
	conditions->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		conditions->meal_target = ft_atol(av[5]);
	else
		conditions->meal_target = -1;
	if (conditions->time_to_die < 60
		|| conditions->time_to_eat < 60
		|| conditions->time_to_sleep < 60)
	{
		ft_putstr("error: time variables must be over 60ms\n");
		return (false);
	}
	if (check_int_max(conditions) == false)
		return (false);
	conditions->start_time = get_current_time();
	if (!create_forks(conditions, conditions->num_of_philos))
		return (false);
	conditions->simulation_ended = false;
	if (pthread_mutex_init(&conditions->lock, NULL) != 0)
		return (false);
	return (true);
}
