/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:47:52 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 18:01:19 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checkdeath(t_philo *p)
{
	long lasteat;

	pthread_mutex_lock(&p->lasteatmutex);
	lasteat = p->lasteat;
	pthread_mutex_unlock(&p->lasteatmutex);
	if (ft_gettime() - lasteat > p->data->titdie)
	{
		pthread_mutex_lock(&p->data->philostopmutex);
		p->data->philostop = 1;
		pthread_mutex_unlock(&p->data->philostopmutex);
		ft_print_data(p, "died", 1);
		return (1);
	}
	return (0);
}

int	ft_checkeats(t_philo *p, int i, int *eatsreached)
{
	int nbeats;

	if (p[i].data->noeatss)
	{
		pthread_mutex_lock(&(p[i].nbeatsmutex));
		nbeats = p[i].nbeats;
		pthread_mutex_unlock(&(p[i].nbeatsmutex));
		if (nbeats < p[0].data->noeats)
			*eatsreached = 0;
		if (i == p[0].data->nophil - 1)
		{
			if (*eatsreached == 1)
			{
				pthread_mutex_lock(&(p[0].data->philostopmutex));
				p[0].data->philostop = 1;
				pthread_mutex_unlock(&(p[0].data->philostopmutex));
				return (1);
			}
			*eatsreached = 1;
		}
	}
	return (0);
}

void	*ft_checkthread(void *philosvoid)
{
	t_philo	*p;
	int		i;
	int		eatsreached;

	p = (t_philo *)philosvoid;
	i = 0;
	eatsreached = 1;
	while (1)
	{
		if (ft_checkdeath(p) || ft_checkeats(p, i, &eatsreached))
			return (NULL);
		if (i == p[0].data->nophil - 1)
		{
			i = 0;
			usleep(500);
		}
		else
			i++;
	}
	return (NULL);
}
