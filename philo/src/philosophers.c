/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:24:14 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/29 02:26:03 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/philosophers.h"

int	main(int ac, char **av)
{
	t_data data;

	if(ac == 5 || ac == 6)
	{
		if (check_args(av))
			return (-1);
		parse_data(&data, av);
		init_data(&data);
		if (run_threads(&data))
			return (-1);
//		monitor_routine(&data);
		free_all(&data);
	}
	else
		print_error(ac);
	return(0);
}
