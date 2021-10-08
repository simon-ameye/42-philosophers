/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:48 by sameye            #+#    #+#             */
/*   Updated: 2021/10/08 12:19:02 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/time.h>


typedef struct s_philo
{
	pthread_t thread;
	int fork;
	int index;
}	t_philo;

typedef struct s_data
{
	int nophil;
	int titdie;
	int titeat;
	int titsle;
	int noeats;
	t_philo *philos;
	pthread_mutex_t strmutex;
}	t_data;

int	ft_atoi(const char *nptr);
int	init_data(t_data *philo_data, int ac, char **av);
int	check_data(int ac, char **av);
int init_philos(t_data *philo_data);
void ft_putstr(char *s, t_data *philo_data);

#endif