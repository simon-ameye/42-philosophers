/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:40 by sameye            #+#    #+#             */
/*   Updated: 2021/11/10 19:07:00 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_mallocphilos(t_data *data)
{
	t_philo	*philos;

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

int	ft_philo(t_data *data)
{
	t_philo		*philos;
	pthread_t	deaththread;

	philos = ft_mallocphilos(data);
	if (philos == NULL)
		return (EXIT_FAILURE);
	ft_createphilos(philos, data);
	pthread_create(&deaththread, NULL, ft_checkthread, philos);
	ft_jointhreads(philos, data);
	pthread_join(deaththread, NULL);
	ft_destroymutex(data);
	free (philos);
	free (data->forks);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (check_data(ac, av) == EXIT_FAILURE)
			return (0);
		init_data(&data, ac, av);
		if (ft_philo(&data) == EXIT_FAILURE)
			return (0);
	}
}
