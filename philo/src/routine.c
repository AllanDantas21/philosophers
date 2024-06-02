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

void	define_forks(t_fork **first_fork, t_fork **second_fork, t_philo *philo)
{
	if (philo->left_fork->fork_id < philo->right_fork->fork_id)
	{
		*first_fork = philo->left_fork;
		*second_fork = philo->right_fork;
	}
	else
	{
		*first_fork = philo->right_fork;
		*second_fork = philo->left_fork;
	}
}

static int	eat(t_philo *philo)
{
	t_fork	*first_fork;
	t_fork	*second_fork;

	define_forks(&first_fork, &second_fork, philo);
	pthread_mutex_lock(&first_fork->fork);
	print_status(philo, FORK);
	if (philo->table->philo_nbr == 1)
		return (-1);
	pthread_mutex_lock(&second_fork->fork);
	print_status(philo, FORK);
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->table->mutex);
	philo->nbr_eats++;
	philo->last_eat = get_time() - philo->start_simulation;
	pthread_mutex_unlock(&philo->table->mutex);
	usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(&first_fork->fork);
	pthread_mutex_unlock(&second_fork->fork);
	return (0);
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

bool	check_all_alive(t_data *data)
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
	if (p->id % 2)
		usleep(1500);
	while (check_all_alive(data) && data->count_full != data->philo_nbr)
	{
		if (eat(p))
			return NULL;
		nap(p);
		think(p);
	}
	return (NULL);
}

int	run_threads(t_data *data)
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
