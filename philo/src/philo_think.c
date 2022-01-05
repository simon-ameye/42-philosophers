/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:03:39 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 19:26:49 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_think_even(t_philo *philo)
{
	pthread_mutex_lock(&(philo->lfork));
	ft_print_data(philo, "has taken a fork", 0);
	pthread_mutex_lock(philo->rfork);
	ft_print_data(philo, "has taken a fork", 0);
}

static void	ft_think_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	ft_print_data(philo, "has taken a fork", 0);
	pthread_mutex_lock(&(philo->lfork));
	ft_print_data(philo, "has taken a fork", 0);
}

void	ft_think(t_philo *philo)
{
	ft_print_data(philo, "is thinking", 0);
	if (philo->index % 2)
		ft_think_even(philo);
	else
		ft_think_odd(philo);
}
