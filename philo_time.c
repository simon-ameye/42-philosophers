/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:11:39 by sameye            #+#    #+#             */
/*   Updated: 2021/11/08 13:12:28 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_printtime(t_data *data)
{
	long int actual_time;
	long int elapsed_time;

	actual_time = ft_gettime();
	elapsed_time = actual_time - data->starti;
	ft_putnum(elapsed_time);
}

long int ft_gettime(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

void ft_usleep(long int pause)
{
	long int start_time;
	long int current_time;

	start_time = ft_gettime();
	current_time = start_time;
	while (current_time - start_time < pause)
	{
		current_time = ft_gettime();
		usleep(pause / 10);
	}
}
