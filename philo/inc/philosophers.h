/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:02:41 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/25 19:14:24 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

typedef pthread_mutex_t	t_mtx;
typedef pthread_t	t_thread;

/* colors */
# define RESET  "\033[0m"      
# define RED	"\033[1;31m"   
# define G      "\033[1;32m"   
# define Y      "\033[1;33m"
# define B      "\033[1;34m"
# define P	"\033[1;35m"
# define C      "\033[1;36m"
# define W      "\033[1;37m"

/* each fork */
typedef struct s_fork
{
	t_mtx	fork_mtx;
	int	id_mtx;
}	t_fork;

/* each philosopher */
typedef struct s_philo
{
	t_thread	thread;
	t_fork		*left_fork;
	t_fork		*rigth_fork;
	int		id;
}	t_philo;

typedef struct s_data
{
	int	philo_nbr;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	eats_total;
}	t_data;

void		init_data(t_data *data, int ac, char **av);
int		ft_atoi(const char *nptr);

/* parsers */
int		check_args(char **av);
void		print_error();

#endif
