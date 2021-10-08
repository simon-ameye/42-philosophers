/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:40 by sameye            #+#    #+#             */
/*   Updated: 2021/10/07 17:25:52 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main (int ac, char **av)
{
	t_data	philo_data;
	
	if (ac == 5 || ac == 6)
	{
		if (check_data(ac, av) == EXIT_FAILURE)
			return (0);
		init_data(&philo_data, ac, av);
		if (init_philos(&philo_data) == EXIT_FAILURE)
			return (0);
	}
}
