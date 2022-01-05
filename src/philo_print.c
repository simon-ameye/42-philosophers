/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:10:52 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 15:03:38 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_data(t_philo *philo, char *str, int bypass)
{
	int philostop;

	pthread_mutex_lock(&(philo->data->printmutex));
	pthread_mutex_lock(&philo->data->philostopmutex);
	philostop = philo->data->philostop;
	pthread_mutex_unlock(&philo->data->philostopmutex);
	if (philostop == 0 || bypass == 1)
	{
		ft_printtime(philo->data);
		ft_putstr(" ");
		ft_putnum(philo->index);
		ft_putstr(" ");
		ft_putstr(str);
		ft_putstr("\n");
	}
	pthread_mutex_unlock(&(philo->data->printmutex));
}
