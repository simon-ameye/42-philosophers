/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:03:41 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 19:28:00 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_sleep(t_philo *philo)
{
	int	philostop;

	pthread_mutex_lock(&(philo->data->philostopmutex));
	philostop = philo->data->philostop;
	pthread_mutex_unlock(&(philo->data->philostopmutex));
	if (!philostop)
	{
		ft_print_data(philo, "is sleeping", 0);
		ft_usleep(philo->data->titsle);
	}
}

static void	*ft_philothread(void *philovoid)
{
	t_philo	*philo;
	int		philostop;

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
			break ;
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
