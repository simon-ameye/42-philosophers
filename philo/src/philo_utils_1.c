/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:10:50 by sameye            #+#    #+#             */
/*   Updated: 2022/01/05 19:28:14 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	write(1, s, ft_strlen(s));
}

static long	ft_getlen(long n)
{
	long	len;

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

static long	ft_pow(long n)
{
	long	i;
	long	res;

	res = 1;
	i = 0;
	while (i < n)
	{
		res = res * 10;
		i++;
	}
	return (res);
}

void	ft_putnum(long n)
{
	long	len;
	char	c;

	len = ft_getlen(n);
	while (len > 0)
	{
		c = (n / ft_pow(len - 1)) % 10 + '0';
		write(1, &c, 1);
		len--;
	}
}
