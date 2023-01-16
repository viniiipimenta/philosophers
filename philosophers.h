/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:10:20 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/16 14:52:18 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int		id;
	int		count_eat;
	int		right_hand;
	int		left_hand;
	long	last_ate;
}			t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				num_philos;
}			t_data;

int			check_num(char *num);
int			check_limit(long num);
int			check_error(char *str[]);

#endif