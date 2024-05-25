/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:08:36 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/25 19:53:50 by aldantas         ###   ########.fr       */
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

	i = 0;
	while(args[i])
	{
		k = 0;
		while(args[i][k])
		{
			if (!ft_isdigit(args[i][k]) && args[i][k] != '+')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	check_limits(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atol(av[i++]) > 2147483647)
			return (1);
	}
	return (0);
}

int	check_args(char **av)
{
	av++;
	if (check_input_digit(av) || check_limits(av))
	{
		write(2, RED"parse error: incorrect input\n"RESET, 36);
		return(-1);
	}
	return (0);
}
