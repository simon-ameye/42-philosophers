/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:47:40 by sameye            #+#    #+#             */
/*   Updated: 2021/10/14 15:33:37 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philos(t_data *data)
{
	int i;
	t_philo *philos;
	pthread_t deaththread;

	data->starti = ft_gettime();
	data->philodead = 0;
	pthread_mutex_init(&data->printmutex, NULL);
	philos = malloc(sizeof(t_philo) * data->nophil);
		if (philos == NULL)
			return (EXIT_FAILURE);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nophil);
		if (data->forks == NULL)
			return (EXIT_FAILURE);
	
	i = 1;
	while (i <= data->nophil)
	{
		philos[i].data = data;
		
		philos[i].lfork = &(data->forks[i]);
		if (i == data->nophil)
			philos[i].rfork = &(data->forks[1]);
		else
			philos[i].rfork = &(data->forks[i + 1]);
		pthread_mutex_init(&(data->forks[i]), NULL);
		philos[i].index = i;
		philos[i].lasteat = data->starti;
		pthread_create(&(philos[i].thread), NULL, philo, (&(philos[i])));
		i++;
	}
	pthread_create(&deaththread, NULL, ft_deathcheck, philos);
	i = 1;
	while (i <= data->nophil)
	{
		pthread_join((philos[i].thread), NULL);
		i++;
	}
	pthread_join(deaththread, NULL);
	return (EXIT_SUCCESS);
}
