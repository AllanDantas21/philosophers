/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:32:56 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/02 21:47:35 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	ft_isdigit(int digit)
{
	return (digit >= '0' && digit <= '9');
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
