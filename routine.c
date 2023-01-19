/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:37:56 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/19 17:46:33 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->right_hand]));
	if (!data->dinner_finish && !data->dead)
		printf("%ldms\t%d\thas taken a fork\n", (get_time() - data->start_time),
			philo->id);
	pthread_mutex_lock(&(data->forks[philo->left_hand]));
	if (!data->dinner_finish && !data->dead)
		printf("%ldms\t%d\thas taken a fork\n", (get_time() - data->start_time),
			philo->id);
	if (check_if_dead(data, philo) == 1 || data->dead == 1)
	{
		pthread_mutex_unlock(&(data->forks[philo->right_hand]));
		pthread_mutex_unlock(&(data->forks[philo->left_hand]));
		return ;
	}
	if (!data->dinner_finish && !data->dead)
		printf("%ldms\t%d\tis eating\n", (get_time() - data->start_time),
			philo->id);
	philo->count_eat++;
	philo->last_ate = get_time();
	//smart_sleep(data, data->eat * 1000);
	usleep(data->eat * 1000);
	pthread_mutex_unlock(&(data->forks[philo->right_hand]));
	pthread_mutex_unlock(&(data->forks[philo->left_hand]));
}

void	doing_routine(t_data *data, t_philo *philo)
{
	if (check_if_dead(data, philo) == 1 || data->dead == 1)
		return ;
	eat(data, philo);
	if (check_ate_time(data, philo) == 1)
		return ;
	if (check_if_dead(data, philo) == 1 || data->dead == 1)
		return ;
	if (!data->dinner_finish && !data->dead)
		printf("%ldms\t%d\tis sleeping\n", (get_time() - data->start_time),
			philo->id);
	//smart_sleep(data, data->sleep * 1000);
	usleep(data->sleep * 1000);
	if (check_if_dead(data, philo) == 1 || data->dead == 1)
		return ;
	if (!data->dinner_finish && !data->dead)
		printf("%ldms\t%d\tis thinking\n", (get_time() - data->start_time),
			philo->id);
}

void	*routine(void *d)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)d;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		doing_routine(data, philo);
		if (data->dead || data->dinner_finish)
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
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philo[i].thread_id, NULL);
}
