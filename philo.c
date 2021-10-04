/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:40 by sameye            #+#    #+#             */
/*   Updated: 2021/10/04 17:49:04 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *philo_data, int ac, char **av)
{
	philo_data->nophil = ft_atoi(av[1]);
	philo_data->titdie = ft_atoi(av[2]);
	philo_data->titeat = ft_atoi(av[3]);
	philo_data->titsle = ft_atoi(av[4]);
	if (ac == 6)
		philo_data->noeats = ft_atoi(av[5]);
	else
		philo_data->noeats = 0;
	return (EXIT_SUCCESS);
}

int init_philos(t_data *philo_data, t_philo **philos)
{
	int i;

	*philos = malloc(sizeof(t_philo) * philo_data->nophil);
		if (philos == NULL)
			return (EXIT_FAILURE);
	i = 0;
	while (i < philo_data->nophil)
	{
		(*philos)[i]->fork = 1;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main (int ac, char **av)
{
	t_philo	*philos;
	t_data	philo_data;
	
	if (ac == 5 || ac == 6)
	{
		printf("%i", atoi(av[ac - 1]));
		if (init_data(&philo_data, ac, av) == EXIT_FAILURE)
			return (0);
		if (init_philos(&philo_data, &philos) == EXIT_FAILURE)
			return (0);
	}
}
