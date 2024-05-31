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

void *routine(void *arg)
{
	t_philo	*p;
	t_data	*data;

	p = (t_philo *)arg;
	data = p->table;
	if (p->id % 2 == 0)
		usleep(100);
	while(data->is_all_alive && p->nbr_eats != data->eats_total)
	{
		eat(p, data);
		nap(p, data);
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
