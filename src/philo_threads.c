/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:47:40 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 18:36:32 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_think_even(t_philo *philo)
{
	pthread_mutex_lock(&(philo->lfork));
	ft_print_data(philo, "has taken a fork", 0);
	pthread_mutex_lock(philo->rfork);
	ft_print_data(philo, "has taken a fork", 0);
}

static void ft_think_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	ft_print_data(philo, "has taken a fork", 0);
	pthread_mutex_lock(&(philo->lfork));
	ft_print_data(philo, "has taken a fork", 0);
}

static void ft_eat_even(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(&(philo->lfork));
}

static void ft_eat_odd(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->lfork));
	pthread_mutex_unlock(philo->rfork);
}

static void ft_think(t_philo *philo)
{
	ft_print_data(philo, "is thinking", 0);
	if (philo->index % 2)
		ft_think_even(philo);
	else 
		ft_think_odd(philo);
}

static void ft_eat(t_philo *philo)
{
	int philostop;

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

static void ft_sleep(t_philo *philo)
{
	int philostop;

	pthread_mutex_lock(&(philo->data->philostopmutex));
	philostop = philo->data->philostop;
	pthread_mutex_unlock(&(philo->data->philostopmutex));
	if (!philostop)
	{
		ft_print_data(philo, "is sleeping", 0);
		ft_usleep(philo->data->titsle);
	}
}

void	*ft_philothread(void *philovoid)
{
	t_philo	*philo;
	int philostop;

	philo = (t_philo *)philovoid;
	if (&(philo->lfork) == philo->rfork)
	{
		ft_usleep(philo->data->titdie);
		return (NULL);
	}
	if (philo->index % 2 == 0)
		usleep(500);
	
	while (1)
	{
		pthread_mutex_lock(&(philo->data->philostopmutex));
		philostop = philo->data->philostop;
		pthread_mutex_unlock(&(philo->data->philostopmutex));
		if (philostop)
			break;
		ft_think(philo);
		ft_eat(philo);
		ft_sleep(philo);

	}
	return (NULL);
}

int	ft_createphilos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->nophil - 1)
	{
		philos[i].data = data;
		philos[i].index = i + 1;
		if (philos[i].index == data->nophil)
			philos[i].rfork = &(philos[0].lfork);
		else
			philos[i].rfork = &(philos[i + 1].lfork);
		philos[i].lasteat = data->starti;
		pthread_create(&(philos[i].thread), NULL,
			ft_philothread, (&(philos[i])));
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_jointhreads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->nophil - 1)
	{
		pthread_join((philos[i].thread), NULL);
		i++;
	}
}
