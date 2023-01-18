/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:37:56 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/18 13:00:49 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printing(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->right_hand]));
	printf("%d has taken a fork\n", philo->id);
	pthread_mutex_lock(&(data->forks[philo->left_hand]));
	printf("%d has taken a fork\n", philo->id);
	printf("%d is eating\n", philo->id);
	usleep(data->eat);
	philo->count_eat++;
	pthread_mutex_unlock(&(data->forks[philo->right_hand]));
	pthread_mutex_unlock(&(data->forks[philo->left_hand]));
	printf("%d is sleeping\n", philo->id);
	usleep(data->sleep);
	printf("%d is thinking\n", philo->id);
}

void	*routine(void *d)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)d;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!philo->data->if_die)
	{
		printing(data, philo);
		
	}
	return (0);
}

void	init_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		pthread_create(&(data->philo[i].thread_id), NULL, &routine,
			&(data->philo[i]));
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philo[i].thread_id, NULL);
}
