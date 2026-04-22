/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:52:59 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/16 17:53:01 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	print_status(t_philo *philo, long time, char *message)
{
	pthread_mutex_lock(&philo->conditions->lock);
	if (philo->conditions->simulation_ended == false)
	{
		ft_putnbr(time);
		ft_putchar(' ');
		ft_putnbr(philo->id);
		ft_putchar(' ');
		ft_putstr(message);
		ft_putchar('\n');
	}
	pthread_mutex_unlock(&philo->conditions->lock);
	return ;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(long nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}
