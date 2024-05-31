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
		if (parse_data(&data, av))
			return (-1);
		init_data(&data);
		run_threads(&data);
		free_all(&data);
	}
	else
		print_error(ac);
	return(0);
}
