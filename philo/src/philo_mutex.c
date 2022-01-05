/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:03:44 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 19:19:46 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initmutex(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->nophil - 1)
	{
		pthread_mutex_init(&(philos[i].lfork), NULL);
		pthread_mutex_init(&(philos[i].lasteatmutex), NULL);
		pthread_mutex_init(&(philos[i].nbeatsmutex), NULL);
		i++;
	}
	pthread_mutex_init(&(data->printmutex), NULL);
	pthread_mutex_init(&data->philostopmutex, NULL);
}

void	ft_destroymutex(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->nophil - 1)
	{
		pthread_mutex_destroy(&(philos[i].lfork));
		pthread_mutex_destroy(&(philos[i].lasteatmutex));
		pthread_mutex_destroy(&(philos[i].nbeatsmutex));
		i++;
	}
	pthread_mutex_destroy(&(data->printmutex));
	pthread_mutex_destroy(&(data->philostopmutex));
}
