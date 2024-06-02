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
	long long now;

	pthread_mutex_lock(&p->table->print_mtx);
	now = get_time() - p->start_simulation;
	if (check_all_alive(p->table) && flag == SLEEP)
		printf (Y"time: %lld, id: %d is sleeping\n"RESET, now, p->id);
	if (check_all_alive(p->table) && flag == THINK)
		printf (C"time: %lld, id: %d is thinking\n"RESET, now, p->id);
	if (check_all_alive(p->table) && flag == EAT)
		printf (G"time: %lld, id: %d is eating\n"RESET, now, p->id);
	if (check_all_alive(p->table) && flag == FORK)
		printf (B"time: %lld, id: %d takes a fork\n"RESET, now, p->id);
	if (!check_all_alive(p->table) && flag == DEAD)
		printf (RED"time: %lld, id: %d is dead\n"RESET, now, p->id);
	pthread_mutex_unlock(&p->table->print_mtx);
}
void	free_all(t_data *data)
{
	int	i;

	i = data->philo_nbr;
	pthread_mutex_destroy(&data->mutex);
	pthread_mutex_destroy(&data->print_mtx);
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

void	print_error(int ac)
{
	if (ac < 5)
		printf(RED"too few arguments\n"RESET);
	else if (ac > 6)
		printf(RED"too more arguments\n"RESET);
}
