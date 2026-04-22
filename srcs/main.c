/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:38:11 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/08 11:38:12 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int ac, char **av)
{
	t_conditions	conditions;
	t_philo			*philo;

	philo = NULL;
	if (validate_args(ac, av) == false)
		return (EXIT_FAILURE);
	if (set_conditions(&conditions, ac, av) == false)
		return (EXIT_FAILURE);
	if (philo_init(&philo, &conditions) == false)
	{
		clean_conditions(&conditions);
		return (EXIT_FAILURE);
	}
	if (conditions.num_of_philos == 1)
		handle_one_philosopher(philo, &conditions);
	else
		start_dinner(philo, &conditions);
	clean_all(philo, &conditions);
	return (EXIT_SUCCESS);
}
