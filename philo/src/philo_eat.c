/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:03:36 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 19:26:25 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat_even(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(&(philo->lfork));
}

static void	ft_eat_odd(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->lfork));
	pthread_mutex_unlock(philo->rfork);
}

void	ft_eat(t_philo *philo)
{
	int	philostop;

	pthread_mutex_lock(&(philo->data->philostopmutex));
	philostop = philo->data->philostop;
	pthread_mutex_unlock(&(philo->data->philostopmutex));
	if (!philostop)
	{
		ft_print_data(philo, "is eating", 0);
		ft_usleep(philo->data->titeat);
	}
	if (philo->index % 2)
		ft_eat_even(philo);
	else
		ft_eat_odd(philo);
	pthread_mutex_lock(&(philo->lasteatmutex));
	philo->lasteat = ft_gettime();
	pthread_mutex_unlock(&(philo->lasteatmutex));
	pthread_mutex_lock(&(philo->nbeatsmutex));
	(philo->nbeats)++;
	pthread_mutex_unlock(&(philo->nbeatsmutex));
}
