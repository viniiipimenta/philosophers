/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:37:56 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/18 16:42:50 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printing(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->right_hand]));
	printf("%ldms %d has taken a fork\n", (get_time() - data->start_time),
		philo->id);
	pthread_mutex_lock(&(data->forks[philo->left_hand]));
	printf("%ldms %d has taken a fork\n", (get_time() - data->start_time),
		philo->id);
	printf("%ldms %d is eating\n", (get_time() - data->start_time), philo->id);
	philo->count_eat++;
	philo->last_ate = get_time() - data->start_time;
	usleep(data->eat * 1000);
	check_ate_time(data, philo);
	pthread_mutex_unlock(&(data->forks[philo->right_hand]));
	pthread_mutex_unlock(&(data->forks[philo->left_hand]));
	printf("%ldms %d is sleeping\n", (get_time() - data->start_time), philo->id);
	usleep(data->sleep * 1000);
	printf("%ldms %d is thinking\n", (get_time() - data->start_time), philo->id);
}

void	*routine(void *d)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)d;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!data->dead && !data->dinner_finish)
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
