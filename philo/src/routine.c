/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:20:52 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/04 15:33:29 by penascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, FORK);
	print_status(philo, EAT);
	philo->nbr_eats++;
	usleep(data->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	nap(t_philo *philo, t_data *data)
{
	print_status(philo, SLEEP);
	usleep(data->time_sleep);
}

static void	think(t_philo *philo)
{
	print_status(philo, THINK);
}

static int	check_all_alive(t_data *data)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&data->mutex);
	if (data->is_all_alive)
		ret = 1;
	pthread_mutex_unlock(&data->mutex);
	return (ret);
}

void	*routine(void *arg)
{
	t_philo	*p;
	t_data	*data;

	p = (t_philo *)arg;
	data = p->table;
	if (p->id % 2 == 0)
		usleep(1500);
	while (check_all_alive(data) && p->nbr_eats != p->eats_total)
	{
		eat(p, data);
		nap(p, data);
		think(p);
	}
	return (NULL);
}
