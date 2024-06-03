/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:32:56 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/02 23:48:46 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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

