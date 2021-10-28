/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:40 by sameye            #+#    #+#             */
/*   Updated: 2021/10/28 18:05:21 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *philovoid)
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

void	*ft_deathcheck(void *philosvoid)
{
	t_philo	*p;
	int		i;
	int		eatsreached;

	p = (t_philo *)philosvoid;
	i = 0;
	eatsreached = 1;
	while (1)
	{
		if (ft_gettime() - (p[i]).lasteat > p[0].data->titdie)
		{
			p[1].data->philostop = 1;
			ft_print_data(&(p[i]), "died", 1);
			return (NULL);
		}
		if (!p[i].data->noeatss || p[i].nbeats < p[0].data->noeats)
			eatsreached = 0;
		if (i == p[0].data->nophil - 1)
		{
			if (eatsreached == 1)
			{
				p[0].data->philostop = 1;
				return (NULL);
			}
			i = 0;
			eatsreached = 1;
		}
		else
			i++;
	}
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
