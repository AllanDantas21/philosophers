/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:10:18 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/29 02:14:08 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/philosophers.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_philo *p, t_status flag)
{
	if (flag == SLEEP)
		printf (Y"time: %d, id: %d is sleeping\n"RESET, p->last_eat, p->id);
	if (flag == THINK)
		printf (C"time: %d, id: %d is thinking\n"RESET, p->last_eat, p->id);
	if (flag == EAT)
		printf (G"time: %d, id: %d is eating\n"RESET, p->last_eat, p->id);
	if (flag == FORK)
		printf (B"time: %d, id: %d takes a fork\n"RESET, p->last_eat, p->id);
	if (flag == DEAD)
		printf (RED"time: %d, id: %d is dead\n"RESET, p->last_eat, p->id);
}
void	free_all(t_data *data)
{
	int	i;

	i = data->philo_nbr;
	pthread_mutex_destroy(&data->mutex);
	while (--i >= 0)
	{
		pthread_mutex_destroy(&data->array_forks[i]);
		free(data->array_philos[i]);
	}
	free(data->array_forks);
	free(data->array_philos);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*nptr == 32) || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += *nptr++ - '0';
	}
	return ((long)(res * sign));
}

