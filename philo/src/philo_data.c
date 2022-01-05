/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:03:52 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 19:16:28 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_data(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (av[i] == NULL)
			return (EXIT_FAILURE);
		j = 0;
		if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			return (EXIT_FAILURE);
		j++;
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

int	init_data(t_data *data, int ac, char **av)
{
	data->nophil = ft_atoi(av[1]);
	data->titdie = ft_atoi(av[2]);
	data->titeat = ft_atoi(av[3]);
	data->titsle = ft_atoi(av[4]);
	data->noeatss = 0;
	data->noeats = 0;
	if (ac == 6)
	{
		data->noeatss = 1;
		data->noeats = ft_atoi(av[5]);
	}
	data->starti = ft_gettime();
	data->philostop = 0;
	return (EXIT_SUCCESS);
}
