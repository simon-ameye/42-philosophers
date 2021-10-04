/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:12:48 by sameye            #+#    #+#             */
/*   Updated: 2021/10/04 17:26:58 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int nophil;
	int titdie;
	int titeat;
	int titsle;
	int noeats;
}	t_data;

typedef struct s_philo
{
	int threadnumber;
	int fork;
	int index;
}	t_philo;


int	ft_atoi(const char *nptr);

#endif