/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:46:12 by sameye            #+#    #+#             */
/*   Updated: 2021/10/07 17:23:55 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_data(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

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