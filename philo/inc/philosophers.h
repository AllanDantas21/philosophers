/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:02:41 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/29 02:58:11 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mtx;
typedef pthread_t		t_thread;
typedef struct s_data	t_data;

/* colors */
# define RESET  "\033[0m"
# define RED	"\033[1;31m"   
# define G      "\033[1;32m"   
# define Y      "\033[1;33m"
# define B      "\033[1;34m"
# define P	"\033[1;35m"
# define C      "\033[1;36m"
# define W      "\033[1;37m"

typedef enum	e_status
{
	SLEEP,
	EAT,
	FORK,
	THINK,
	DEAD
}	t_status;

/* each philosopher */
typedef struct s_philo
{
	int		id;			// id do filosofo
	int		nbr_eats;		// quantas vezes ele comeu
	int		eats_total;	// copia do eats_total do data;
	int		last_eat;
	int		time_eat;	// copia do time_eat do data;
	int		time_sleep;	// copia do time_sleep do data;
	bool		is_alive;	// flag para saber se o philo esta vivo;
	t_thread	thread;		// cada filosofo vai ser uma thread
	t_mtx		*left_fork;	// garfo esquerdo
	t_mtx		*right_fork;// garfo direito
	t_data		*table;
}	t_philo;

/* datas */
typedef struct s_data
{
	int		philo_nbr;		// numero de filosofos
	int		time_die;		// tempo para morrer
	int		time_eat;		// tempo parar comer 
	int		time_sleep;		// tempo para dormir
	int		eats_total;		// variavel opcional para o quinto paramentro;
	long	time_simulation; // vai contar o tempo da simulação
	bool	is_all_alive;	 // flag para saber se todos estão vivos -> se um morrer para o programa
	t_mtx	mutex;		// 
	t_mtx	*array_forks;	// array de forks -> um para cada filosofo 
	t_philo	**array_philos;	// array dos filosofos
}	t_data;

/* inits */
void		parse_data(t_data *data, char **av); // fazer o parsing das informações
int			init_data(t_data *data);			// iniciar as threads e mutexes

/* routine */
int		run_threads(t_data *data);	// dar join nos threads
void	*routine(void *arg);		// função de rotina dos threads
int	monitor_routine(t_data *arg);
int	check_is_alive(t_philo	*philo);

/* utils */
long		ft_atol(const char *nptr);
void		free_all(t_data *data);		// free em tudo
long long	get_time(void);			// função de tempo -> tem que testar ainda
void		print_status(t_philo *p, t_status flag);

/* parsers */
int			check_args(char **av);
void		print_error();

#endif
