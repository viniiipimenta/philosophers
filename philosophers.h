/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:10:20 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/23 13:28:33 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				count_eat;
	int				right_hand;
	int				left_hand;
	long			last_ate;
	pthread_t		thread_id;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	long			die;
	long			eat;
	long			sleep;
	int				must_eat;
	int				num_philos;
	long			start_time;
	int				dead;
	int				dinner_finish;
	pthread_mutex_t	check_eat;
	pthread_mutex_t	check_dead;
	pthread_mutex_t	lock_print;
}					t_data;

int					ft_atoi(const char *str);
int					ft_isdigit(char c);

int					check_num(char *num);
int					check_limit(long num);
int					check_error(char *str[]);
long				get_time(void);
void				create_forks(t_data *data);
void				init_threads(t_data *data);
void				destroy_forks(t_data *data);
int					check_ate_time(t_data *data, t_philo *philo);
int					check_if_dead(t_data *data, t_philo *philo);
void				smart_sleep(t_data *data, t_philo *philo, long time);
void				print_msg(t_data *data, t_philo *philo, char way);

#endif