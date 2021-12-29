/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:10:52 by sameye            #+#    #+#             */
/*   Updated: 2021/11/10 19:01:04 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_data(t_philo *philo, char *str, int bypass)
{
	if (philo->data->philostop == 1 && bypass == 0)
	{
		//fprintf(stderr, "philo %i tried to print but was bypassed. passing : %s\n", philo->index, str);
		return ;
	}
	pthread_mutex_lock(&(philo->data->printmutex));
	if (philo->data->philostop == 1 && bypass == 0)
	{
		pthread_mutex_unlock(&(philo->data->printmutex));
		return ;
	}
	ft_printtime(philo->data);
	ft_putstr(" ");
	ft_putnum(philo->index);
	ft_putstr(" ");
	ft_putstr(str);
	ft_putstr("\n");
	pthread_mutex_unlock(&(philo->data->printmutex));
}
