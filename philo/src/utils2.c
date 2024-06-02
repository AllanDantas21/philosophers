/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:32:56 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/01 20:47:53 by aldantas         ###   ########.fr       */
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
