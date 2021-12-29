/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:17:51 by sameye            #+#    #+#             */
/*   Updated: 2021/11/10 19:05:09 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

long	ft_getlen(long n)
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

long	ft_pow(long n)
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

void	print_stamps(long len)
{
	int i;

	i = 0;
	while (i <= 7 - len)
	{
		write(1, ".", 1);
		i++;
	}
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

void	ft_putstamp(long n)
{
	long	len;

	len = ft_getlen(n);
	print_stamps(len);
	ft_putnum(n);
}
