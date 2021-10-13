/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:47:40 by sameye            #+#    #+#             */
/*   Updated: 2021/10/14 00:06:09 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo(void *philovoid)
{
	t_philo *philo;

	philo = (t_philo *)philovoid;
	if (philo->index % 2 == 0)
		ft_usleep(philo->data->titeat / 10);

	while (1)
	{
		if (philo->data->philodead)
			return (NULL);
		ft_print_data(philo, "is thinking");
		pthread_mutex_lock(philo->lfork);
		if (philo->data->philodead)
			return (NULL);
		ft_print_data(philo, "has taken a fork");
		pthread_mutex_lock(philo->rfork);
		if (philo->data->philodead)
			return (NULL);
		ft_print_data(philo, "has taken a fork");
		if (philo->data->philodead)
			return (NULL);
		ft_print_data(philo, "is eating");
		ft_usleep(philo->data->titeat);
		philo->lasteat = ft_gettime();
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->rfork);
		if (philo->data->philodead)
			return (NULL);
		ft_print_data(philo, "is sleeping");
		ft_usleep(philo->data->titsle);
	}
	return (NULL);
}

void *ft_deathcheck(void *philosvoid)
{
	t_philo *philos;
	int i;
	int nophil;
	int titdie;

	philos = (t_philo *)philosvoid;
	nophil = philos[1].data->nophil;
	titdie = philos[1].data->titdie;
	i = 1;
	while (1)
	{
		if (ft_gettime() - (philos[i]).lasteat  > titdie)
		{
			ft_print_data(&(philos[i]), "died");
			philos[1].data->philodead = 1;
			return (NULL);
		}
		if (i == nophil)
			i = 1;
		else;
			i++;
	}
	return (NULL);
}

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
			philos[i].rfork = &(data->forks[0]);
		else
			philos[i].rfork = &(data->forks[i + 1]);
		
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
