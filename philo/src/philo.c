/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:04:44 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 19:12:42 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philo(t_data *data)
{
	t_philo		*philos;
	pthread_t	deaththread;

	philos = malloc(sizeof(t_philo) * data->nophil);
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
			return (EXIT_FAILURE);
		init_data(&data, ac, av);
		if (ft_philo(&data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
