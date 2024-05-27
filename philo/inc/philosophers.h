/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:02:41 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/26 01:12:01 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>

typedef pthread_mutex_t	t_mtx;
typedef pthread_t		t_thread;

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
	t_mtx	fork_mtx;	// cada garfo vai ser um mutex
	int	id_mtx;			// id de cada garfo
}	t_fork;

/* each philosopher */
typedef struct s_philo
{
	t_thread	thread;		// cada filosofo vai ser uma thread
	t_fork		*left_fork;	// garfo esquerdo
	t_fork		*right_fork;// garfo direito
	int			id;			// id do filosofo
	t_data		data;
}	t_philo;

/* datas */
typedef struct s_data
{
	int		philo_nbr;		// numero de filosofos
	int		time_die;		// tempo para morrer
	int		time_eat;		// tempo parar comer 
	int		time_sleep;		// tempo para dormir
	int		eats_total;		// variavel opcional para o quinto paramentro
	long	time_simulation; // vai contar o tempo da simulação
	bool	is_all_alive;	 // flag para saber se todos estão vivos -> se um morrer para o programa
	t_fork	*array_forks;	// array de forks -> um para cada filosofo 
	t_philo	*array_philos;	// array dos filosofos
}	t_data;

/* inits */
void		parse_data(t_data *data, char **av);

/* utils */
long		ft_atol(const char *nptr);

/* parsers */
int			check_args(char **av);
void		print_error();

#endif
