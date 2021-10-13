/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:40 by sameye            #+#    #+#             */
/*   Updated: 2021/10/13 22:06:55 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//eatingsleepingthinking

#include "philo.h"

/*
void ft_eat(t_philo *philo, int index)
{

	while (1)
	{
		ft_print_data(philo, "is thinking");
		pthread_mutex_lock(&(philo->lfork));
		pthread_mutex_lock(&(philo->rfork));
		ft_print_data(philo, "has taken a fork");
	}
	ft_print_data(index, "is eating");
	ft_usleep(philo->data->titeat);
}

void ft_sleep(t_philo *philo)
{
	ft_print_data(philo, "is sleeping");
	ft_usleep(philo->data->titsle);
}

*/


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
