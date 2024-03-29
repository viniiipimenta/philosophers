/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:23:40 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/23 13:25:27 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_forks(t_data *data)
{
	int	i;

	i = data->num_philos;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	while (--i >= 0)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->check_eat, NULL);
	pthread_mutex_init(&data->check_dead, NULL);
	pthread_mutex_init(&data->lock_print, NULL);
}

void	destroy_forks(t_data *data)
{
	int	i;

	i = data->num_philos;
	while (--i >= 0)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->check_dead));
	pthread_mutex_destroy(&(data->check_eat));
	pthread_mutex_destroy(&data->lock_print);
	free(data->forks);
}
