/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:47:52 by sameye            #+#    #+#             */
/*   Updated: 2021/11/10 18:55:27 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checkdeath(t_philo *p)
{
	if (ft_gettime() - p->lasteat > p->data->titdie)
	{
		p->data->philostop = 1;
		ft_print_data(p, "died", 1);
		return (1);
	}
	return (0);
}

int	ft_checkeats(t_philo *p, int i, int *eatsreached)
{
	if (p[i].data->noeatss)
	{
		if (p[i].nbeats < p[0].data->noeats)
			*eatsreached = 0;
		if (i == p[0].data->nophil - 1)
		{
			if (*eatsreached == 1)
			{
				p[0].data->philostop = 1;
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
			i = 0;
		else
			i++;
	}
	return (NULL);
}
