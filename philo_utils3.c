/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:11:36 by sameye            #+#    #+#             */
/*   Updated: 2021/10/28 17:13:11 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_unlock_forks(t_philo *philo)
{
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
}