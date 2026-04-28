/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:38:35 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/08 11:38:36 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static bool	validate_num(char *arg)
{
	int	i;

	i = 0;
	if (!arg[i] || arg[i] == '-')
	{
		ft_putstr("Invalid argument: only positive numbers are accepted\n");
		return (false);
	}
	while (arg[i])
	{
		if (!is_digit(arg[i]))
		{
			ft_putstr("Invalid argument: only numbers are accepted\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	validate_args(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
	{
		ft_putstr("usage: ./philo number_of_philosophers time_to_die ");
		ft_putstr("time_to_eat time_to_sleep [maximum amout of meals]\n");
		return (false);
	}
	i = 1;
	while (i < ac)
	{
		if (validate_num(av[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

void	ft_sleep(long time_to_sleep, t_philo *philo)
{
	size_t	initial_time;

	initial_time = get_current_time();
	while (get_current_time() - initial_time < (size_t)time_to_sleep)
	{
		if (check_death(philo) == true)
			return ;
		usleep(100);
	}
	return ;
}

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
