/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:02:41 by aldantas          #+#    #+#             */
<<<<<<<< HEAD:philo/includes/philosophers.h
/*   Updated: 2024/06/04 15:38:42 by penascim         ###   ########.fr       */
========
/*   Updated: 2024/06/03 20:14:05 by aldantas         ###   ########.fr       */
>>>>>>>> main:philo/includes/philo.h
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mtx;
typedef pthread_t	t_thread;
typedef struct s_data	t_data;

/*	colors		*/
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

typedef struct s_fork
{
	t_mtx	fork;
	int	fork_id;
}				t_fork;

/* each philosopher */
typedef struct s_philo
{
<<<<<<<< HEAD:philo/includes/philosophers.h
	int		id;			// id do filosofo
	int			nbr_eats;		// quantas vezes ele comeu
	int			eats_total;
========
	int16_t		id;			// id do filosofo
	bool		is_full;		// se o filosofo estiver satisfeito
	int		nbr_eats;		// quantas vezes ele comeu
	int		last_eat;		// ultima vez que o filosofo comeu
>>>>>>>> main:philo/includes/philo.h
	t_thread	thread;		// cada filosofo vai ser uma thread
	t_fork		*left_fork;	// garfo esquerdo
	t_fork		*right_fork;	// garfo direito
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
	int		count_full;
	long	start_simulation; // 	vai contar o tempo da simulação
	bool	is_all_alive;	 // flag para saber se todos estão vivos -> se um morrer para o programa;
	t_mtx	mutex;		//	mutex para acesso a qualquer variavel da data;
	t_mtx	print_mtx;	//	mutex para printar uma mensagem;
	t_fork	*array_forks;	// array de forks -> um para cada filosofo 
	t_philo	**array_philos;	// array dos filosofos
}	t_data;


<<<<<<<< HEAD:philo/includes/philosophers.h
/* routine */
int			run_threads(t_data *data);	// dar join nos threads
void		*routine(void *arg);		// função de rotina dos threads

/* utils */
========
int		parse_data(t_data *data, char **av); // fazer o parsing das informações
int		init_data(t_data *data);			// iniciar as threads e mutexes
void		*routine(void *arg);
int		monitor_routine(t_data *arg);
>>>>>>>> main:philo/includes/philo.h
long		ft_atol(const char *nptr);
void		free_all(t_data *data);		// free em tudo
long long	get_time(void);			// função de tempo -> tem que testar ainda
void		print_status(t_philo *p, t_status flag);
<<<<<<<< HEAD:philo/includes/philosophers.h

/* parsers */
int			check_args(char **av);
void		print_error(void);
========
bool		check_all_alive(t_data *data);
int		check_args(char **av);
void		print_error();
void		smart_sleep(t_data *t, long long time);
>>>>>>>> main:philo/includes/philo.h

#endif
