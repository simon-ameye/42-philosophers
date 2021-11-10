/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:47:40 by sameye            #+#    #+#             */
/*   Updated: 2021/11/10 17:13:17 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_createphilos(t_philo *philos, t_data *data)
{
	int i;

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
		pthread_create(&(philos[i].thread), NULL, ft_philothread, (&(philos[i])));
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_jointhreads(t_philo *philos, t_data *data)
{
	int i;

	i = 0;
	while (i <= data->nophil - 1)
	{
		pthread_join((philos[i].thread), NULL);
		i++;
	}
}

void	ft_destroymutex(t_data *data)
{
	int i;

	i = 0;
	while (i <= data->nophil - 1)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&data->printmutex);
}

t_philo *ft_mallocphilos(t_data *data)
{
	t_philo *philos;

	philos = malloc(sizeof(t_philo) * data->nophil);
		if (philos == NULL)
			return (NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nophil);
		if (data->forks == NULL)
		{
			free (philos);
			return (NULL);
		}
		return (philos);
}

int init_philos(t_data *data)
{
	t_philo *philos;
	pthread_t deaththread;

	philos = ft_mallocphilos(data);
	if (philos == NULL)
		return (EXIT_FAILURE);
	ft_createphilos(philos, data);
	pthread_create(&deaththread, NULL, ft_deaththread, philos);
	ft_jointhreads(philos, data);
	pthread_join(deaththread, NULL);
	ft_destroymutex(data);
	free (philos);
	free (data->forks);
	return (EXIT_SUCCESS);
}

void	*ft_deaththread(void *philosvoid)
{
	t_philo	*p;
	int		i;
	int		eatsreached;

	p = (t_philo *)philosvoid;
	i = 0;
	eatsreached = 1;
	while (1)
	{
		if (ft_gettime() - (p[i]).lasteat > p[0].data->titdie)
		{
			p[1].data->philostop = 1;
			ft_print_data(&(p[i]), "died", 1);
			return (NULL);
		}
		if (!p[i].data->noeatss || p[i].nbeats < p[0].data->noeats)
			eatsreached = 0;
		if (i == p[0].data->nophil - 1)
		{
			if (eatsreached == 1)
			{
				p[0].data->philostop = 1;
				return (NULL);
			}
			i = 0;
			eatsreached = 1;
		}
		else
			i++;
	}
	return (NULL);
}
