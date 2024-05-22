/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:24:14 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/22 20:41:48 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo(int ac, char **av)
{
	t_data	data;

	init_data(&data, ac, av);
}

int	main(int ac, char **av)
{
	if(ac == 3 || ac == 4)
	{
		if (check_args(ac, av))
			return (-1);
		philo(ac, av);
	}
	else
		printf("incorrect arguments\n");
	return(0);
}
