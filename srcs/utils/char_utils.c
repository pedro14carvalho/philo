/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:56:08 by josepedr          #+#    #+#             */
/*   Updated: 2026/04/16 17:56:11 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

inline bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(char *str)
{
	long	result;

	result = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	while (is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result);
}
