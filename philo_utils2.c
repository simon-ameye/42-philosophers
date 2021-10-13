/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:15:13 by sameye            #+#    #+#             */
/*   Updated: 2021/10/13 17:49:40 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_putstr(char *s)
{
	int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

long ft_getlen(long n)
{
	long len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

long ft_pow(long n)
{
	long i;
	long res;

	res = 1;
	i = 0;
	while (i < n)
	{
		res = res * 10;
		i++;
	}
	return (res);
}

void ft_putnum(long n)
{
	long len;
	char c;
	
	len = ft_getlen(n);
	while (len > 0)
	{
		c = (n / ft_pow(len - 1)) % 10 + '0';
		write(1, &c, 1);
		len--;
	}
}