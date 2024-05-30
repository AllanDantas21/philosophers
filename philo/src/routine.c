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


void *routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	print_status(p, EAT);
	print_status(p, SLEEP);
	print_status(p, DEAD);
	print_status(p, THINK);
	print_status(p, FORK);
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
