/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:10:18 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/22 20:14:52 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data, int ac, char **av)
{
	data->nbr_of_philosophers = av[1];
	data->time_to_die = av[2];
	data->time_to_eat = av[3]
	data->time_to_sleep = av[4];
	if (ac == 5)
		data->nbr_philos_eats = av[5];
	else
		data->nb_philos_eats = 0;
}
