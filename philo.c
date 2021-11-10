/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:40 by sameye            #+#    #+#             */
/*   Updated: 2021/11/10 17:07:40 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philothread(void *philovoid)
{
	t_philo	*philo;

	philo = (t_philo *)philovoid;
	if (philo->index % 2 == 0)
		ft_usleep(philo->data->titeat / 10);
	while (1)
	{
		ft_print_data(philo, "is thinking", 0);
		pthread_mutex_lock(philo->lfork);
		ft_print_data(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->rfork);
		ft_print_data(philo, "has taken a fork", 0);
		if (philo->data->philostop)
			break ;
		ft_print_data(philo, "is eating", 0);
		ft_usleep(philo->data->titeat);
		ft_unlock_forks(philo);
		philo->lasteat = ft_gettime();
		(philo->nbeats)++;
		ft_print_data(philo, "is sleeping", 0);
		ft_usleep(philo->data->titsle);
	}
	ft_unlock_forks(philo);
	return (NULL);
}

int	main(int ac, char **av)
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
