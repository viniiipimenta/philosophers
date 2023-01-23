/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:37:56 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/23 15:48:12 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	one_philo(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->right_hand]));
	print_msg(data, philo, 'f');
	smart_sleep(data, philo, data->die);
	pthread_mutex_unlock(&(data->forks[philo->right_hand]));
	check_if_dead(data, philo);
}

void	eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->right_hand]));
	print_msg(data, philo, 'f');
	pthread_mutex_lock(&(data->forks[philo->left_hand]));
	print_msg(data, philo, 'f');
	if (check_if_dead(data, philo) == 1)
	{
		pthread_mutex_unlock(&(data->forks[philo->right_hand]));
		pthread_mutex_unlock(&(data->forks[philo->left_hand]));
		return ;
	}
	print_msg(data, philo, 'e');
	philo->count_eat++;
	philo->last_ate = get_time();
	smart_sleep(data, philo, data->eat);
	pthread_mutex_unlock(&(data->forks[philo->right_hand]));
	pthread_mutex_unlock(&(data->forks[philo->left_hand]));
}

void	doing_routine(t_data *data, t_philo *philo)
{
	if (check_if_dead(data, philo) == 1)
		return ;
	eat(data, philo);
	if (check_ate_time(data, philo) == 1 || check_if_dead(data, philo) == 1)
		return ;
	print_msg(data, philo, 's');
	smart_sleep(data, philo, data->sleep);
	if (check_if_dead(data, philo) == 1)
		return ;
	print_msg(data, philo, 's');
}

void	*routine(void *d)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)d;
	data = philo->data;
	if (data->num_philos == 1)
	{
		one_philo(data, philo);
		return (0);
	}
	if (philo->id % 2 == 0)
		usleep(400);
	while (1)
	{
		doing_routine(data, philo);
		if (check_if_dead(data, philo) == 1 || check_ate_time(data, philo) == 1)
			break ;
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
	while (1)
	{
		i = -1;
		while (++i < data->num_philos)
			check_if_dead(data, &data->philo[i]);
		if (data->dead > 0)
			break ;
	}
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philo[i].thread_id, NULL);
}
