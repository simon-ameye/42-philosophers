/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:48 by sameye            #+#    #+#             */
/*   Updated: 2021/10/28 17:21:46 by sameye           ###   ########.fr       */
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

typedef struct s_data
{
	int				nophil;
	int				titdie;
	int				titeat;
	int				titsle;
	int				noeats;
	int				noeatss;
	long int		starti;
	int				philostop;
	pthread_mutex_t	printmutex;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	int				index;
	t_data			*data;
	long int		lasteat;
	int				nbeats;
}	t_philo;

int	ft_atoi(const char *nptr);
int	init_data(t_data *philo_data, int ac, char **av);
int	check_data(int ac, char **av);
int init_philos(t_data *data);
void ft_putstr(char *s);
void ft_usleep(long int pause);
void ft_putnum(long n);
void ft_printtime(t_data *data);
void ft_sleep(t_philo *philo);
void ft_print_data(t_philo *philo, char *str, int bypass);
long int ft_gettime(void);
void *ft_deathcheck(void *philosvoid);
void *philo(void *philovoid);
void ft_unlock_forks(t_philo *philo);



#endif