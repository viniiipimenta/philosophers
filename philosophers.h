/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:10:20 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/18 13:16:40 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				count_eat;
	int				right_hand;
	int				left_hand;
	long			last_ate;
	pthread_t		thread_id;
	struct s_data	*data;
}			t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				die;
	int				dead;
	int				eat;
	int				sleep;
	int				must_eat;
	int				num_philos;
}			t_data;

int			check_num(char *num);
int			check_limit(long num);
int			check_error(char *str[]);
void		create_forks(t_data *data);
void		init_threads(t_data *data);
void		destroy_forks(t_data *data);
void	    check_ate_time(t_data *data, t_philo *philo);

#endif