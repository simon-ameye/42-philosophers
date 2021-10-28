/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:17:51 by sameye            #+#    #+#             */
/*   Updated: 2021/10/28 14:55:56 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
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

long int ft_gettime(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

void ft_printtime(t_data *data)
{
	long int actual_time;
	long int elapsed_time;

	actual_time = ft_gettime();
	elapsed_time = actual_time - data->starti;
	ft_putnum(elapsed_time);
}


void ft_print_data(t_philo *philo, char *str, int bypass)
{
	if (philo->data->philostop == 1 && bypass == 0)
		return ;
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
