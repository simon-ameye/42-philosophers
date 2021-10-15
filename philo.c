/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:40 by sameye            #+#    #+#             */
/*   Updated: 2021/10/15 11:28:47 by sameye           ###   ########.fr       */
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
		if (philo->data->philostop)
			return (NULL);
		ft_print_data(philo, "is thinking");
		pthread_mutex_lock(philo->lfork);
		if (philo->data->philostop)
			return (NULL);
		ft_print_data(philo, "has taken a fork");
		pthread_mutex_lock(philo->rfork);
		if (philo->data->philostop)
			return (NULL);
		ft_print_data(philo, "has taken a fork");
		if (philo->data->philostop)
			return (NULL);
		ft_print_data(philo, "is eating");
		ft_usleep(philo->data->titeat);
		philo->lasteat = ft_gettime();
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		(philo->nbeats)++;
		if (philo->data->philostop)
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
	int eatsreached;

	philos = (t_philo *)philosvoid;
	nophil = philos[1].data->nophil;
	titdie = philos[1].data->titdie;
	i = 1;
	eatsreached = 1;
	while (1)
	{
		
		if (ft_gettime() - (philos[i]).lasteat  > titdie)
		{
			ft_print_data(&(philos[i]), "died");
			philos[1].data->philostop = 1;
			return (NULL);
		}
		if (philos[i].data->noeatsspecified == 0 || philos[i].nbeats < philos[i].data->noeats)
		{
			eatsreached = 0;
		}
		if (i == nophil)
		{
			if (eatsreached == 1)
			{
				philos[1].data->philostop = 1;
				return (NULL);
			}
			i = 1;
			eatsreached = 1;
		}
		else
			i++;
	}
	return (NULL);
}

int	main (int ac, char **av)
{
	t_data	data;
	
	if (ac == 5 || ac == 6)
	{
		if (check_data(ac, av) == EXIT_FAILURE)
			return (0);
		init_data(&data, ac, av);
		if (init_philos(&data) == EXIT_FAILURE)
			return (0);
	}
}
