/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:40 by sameye            #+#    #+#             */
/*   Updated: 2022/01/04 17:37:41 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_mallocphilos(t_data *data)
{
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * data->nophil);
	if (philos == NULL)
		return (NULL);
	return (philos);
}

static void ft_initmutex(t_philo *philos, t_data *data)
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
	pthread_mutex_init(&data->printmutex, NULL);
}

static void	ft_destroymutex(t_philo *philos, t_data *data)
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
	pthread_mutex_destroy(&data->printmutex);
}


int	ft_philo(t_data *data)
{
	t_philo		*philos;
	pthread_t	deaththread;

	philos = ft_mallocphilos(data);
	if (philos == NULL)
		return (EXIT_FAILURE);
	ft_initmutex(philos, data);
	ft_createphilos(philos, data);
	pthread_create(&deaththread, NULL, ft_checkthread, philos);
	ft_jointhreads(philos, data);
	pthread_join(deaththread, NULL);
	ft_destroymutex(philos, data);
	free (philos);
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
