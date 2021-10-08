/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:17:51 by sameye            #+#    #+#             */
/*   Updated: 2021/10/08 12:20:39 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_putstr(char *s, t_data *philo_data)
{
	int i;

	if (s == NULL)
		return ;
	pthread_mutex_lock(&philo_data->strmutex);
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	pthread_mutex_unlock(&philo_data->strmutex);
}

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
	struct timeval time;
	long int start_time;
	long int current_time;

	gettimeofday(&time, NULL);
	start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	current_time = start_time;
	while (current_time - start_time < pause)
	{
		gettimeofday(&time, NULL);
		current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		usleep(pause / 10);
	}
}