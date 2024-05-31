/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:20:52 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/29 02:35:42 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/philosophers.h"

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, FORK);
	print_status(philo, EAT);
	philo->nbr_eats++;
	philo->last_eat = get_time();
	usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	nap(t_philo *philo)
{
	print_status(philo, SLEEP);
	usleep(philo->time_sleep * 1000);
}

static void	think(t_philo *philo)
{
	print_status(philo, THINK);
}

static bool	check_all_alive(t_data *data)
{
	bool	ret;

	ret = true;
	pthread_mutex_lock(&data->mutex);
	if (data->is_all_alive == false)
		ret = false;
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
		eat(p);
		nap(p);
		think(p);
	}
	return (NULL);
}

int  run_threads(t_data *data)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < data->philo_nbr)
	{
		ret = pthread_join(data->array_philos[i]->thread, NULL);
		if (ret)
			return (ret);
	}
	return (ret);
}
