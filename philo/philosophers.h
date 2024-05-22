/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:02:41 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/22 20:30:02 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_fork
{
	int	id;
}	t_fork;

typedef struct s_philo
{
	int	id;
}	t_philo;

typedef struct s_data
{
	int	nbr_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_philos_eats;
}	t_data;

void	init_data(t_data *data, int ac, char **av);
int	check_args(int ac, char **av);
int	ft_atoi(const char *nptr);

#endif
