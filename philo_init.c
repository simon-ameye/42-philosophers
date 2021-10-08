/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:47:40 by sameye            #+#    #+#             */
/*   Updated: 2021/10/08 12:32:24 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void mutexputstr()

void *philo(void *philo_data)
{
	(void)philo_data;
	ft_putstr("AZERTYUIOPazertyuiop ", philo_data);
	return (NULL);
}

int init_philos(t_data *philo_data)
{
	int i;

	pthread_mutex_init(&philo_data->strmutex, NULL);
	philo_data->philos = malloc(sizeof(t_philo) * philo_data->nophil);
		if (philo_data->philos == NULL)
			return (EXIT_FAILURE);
	i = 1;
	while (i <= philo_data->nophil)
	{
		philo_data->philos[i].fork = 0;
		philo_data->philos[i].index = i;
		pthread_create(&(philo_data->philos[i].thread), NULL, philo, philo_data);
		i++;
	}
	i = 1;
	while (i <= philo_data->nophil)
	{
		pthread_join((philo_data->philos[i].thread), NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}