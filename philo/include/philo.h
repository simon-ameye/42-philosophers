/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:48 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 19:23:14 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nophil;
	int				titdie;
	int				titeat;
	int				titsle;
	int				noeats;
	int				noeatss;
	long int		starti;
	pthread_mutex_t	philostopmutex;
	int				philostop;
	pthread_mutex_t	printmutex;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	lfork;
	pthread_mutex_t	*rfork;
	int				index;
	t_data			*data;
	pthread_mutex_t	lasteatmutex;
	long int		lasteat;
	pthread_mutex_t	nbeatsmutex;
	int				nbeats;
}	t_philo;

void		*ft_checkthread(void *philosvoid);
int			check_data(int ac, char **av);
int			init_data(t_data *data, int ac, char **av);
void		ft_eat(t_philo *philo);
void		ft_initmutex(t_philo *philos, t_data *data);
void		ft_destroymutex(t_philo *philos, t_data *data);
void		ft_print_data(t_philo *philo, char *str, int bypass);
void		ft_think(t_philo *philo);
int			ft_createphilos(t_philo *philos, t_data *data);
void		ft_jointhreads(t_philo *philos, t_data *data);
long int	ft_gettime(void);
void		ft_usleep(long int pause);
void		ft_printtime(t_data *data);
void		ft_putstr(char *s);
void		ft_putnum(long n);
int			ft_atoi(const char *nptr);
int			main(int ac, char **av);

#endif