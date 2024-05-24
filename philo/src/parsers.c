/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:08:36 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/23 23:21:10 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	ft_isdigit(int digit)
{
	return (digit >= '0' && digit <= '9');
}

int	check_input_digit(char **args)
{
	int	i;
	int	k;

	args++;
	i = 0;
	while(args[i])
	{
		k = 0;
		while(args[i][k])
		{
			if (!ft_isdigit(args[i][k]))
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	check_args(char **av)
{
	if (check_input_digit(av))
		return(-1);
	return (0);
}
