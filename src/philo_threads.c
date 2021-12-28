/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:47:40 by sameye            #+#    #+#             */
/*   Updated: 2021/11/10 19:07:33 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

void	*ft_philothread(void *philovoid)
{
	t_philo	*philo;

	philo = (t_philo *)philovoid;
	if (philo->index % 2 == 0)
		ft_usleep(philo->data->titeat / 10);
	while (1)
	{
		ft_print_data(philo, "is thinking", 0);
		pthread_mutex_lock(philo->lfork);
		ft_print_data(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->rfork);
		ft_print_data(philo, "has taken a fork", 0);
		if (philo->data->philostop)
			break ;
		ft_print_data(philo, "is eating", 0);
		ft_usleep(philo->data->titeat);
		ft_unlock_forks(philo);
		philo->lasteat = ft_gettime();
		(philo->nbeats)++;
		ft_print_data(philo, "is sleeping", 0);
		ft_usleep(philo->data->titsle);
	}
	ft_unlock_forks(philo);
	return (NULL);
}

int	ft_createphilos(t_philo *philos, t_data *data)
{
	int	i;

	pthread_mutex_init(&data->printmutex, NULL);
	i = 0;
	while (i <= data->nophil - 1)
	{
		philos[i].data = data;
		philos[i].lfork = &(data->forks[i]);
		if (i == data->nophil)
			philos[i].rfork = &(data->forks[0]);
		else
			philos[i].rfork = &(data->forks[i + 1]);
		pthread_mutex_init(&(data->forks[i]), NULL);
		philos[i].index = i + 1;
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

void	ft_destroymutex(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->nophil - 1)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&data->printmutex);
}
