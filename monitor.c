/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:04:37 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/23 14:09:13 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_ate_time(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->check_eat));
	if (data->dinner_finish == 1)
	{
		pthread_mutex_unlock(&(data->check_eat));
		return (1);
	}
	if (philo->count_eat == data->must_eat && data->must_eat > 0)
	{
		data->dinner_finish = 1;
		pthread_mutex_unlock(&(data->check_eat));
		return (1);
	}
	pthread_mutex_unlock(&(data->check_eat));
	return (0);
}

int	check_if_dead(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->check_dead));
	if (data->dead >= 1)
	{
		pthread_mutex_unlock(&(data->check_dead));
		return (1);
	}
	if (data->die <= get_time() - philo->last_ate)
	{
		data->dead++;
		usleep(100);
		if (check_ate_time(data, philo) == 1 || data->dead == 1)
		{
			pthread_mutex_lock(&(data->lock_print));
			printf("%ldms\t%d\tDied\n", get_time() - data->start_time,
				philo->id);
			pthread_mutex_unlock(&(data->lock_print));
		}
		pthread_mutex_unlock(&(data->check_dead));
		return (1);
	}
	pthread_mutex_unlock(&(data->check_dead));
	return (0);
}

long	get_time(void)
{
	struct timeval	time;
	long			current_time;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec * 1000;
	current_time += time.tv_usec / 1000;
	return (current_time);
}

void	smart_sleep(t_data *data, t_philo *philo, long time)
{
	long	start;
	long	now;

	start = get_time();
	now = start;
	while (now - start < time)
	{
		now = get_time();
		usleep(400);
		if (check_ate_time(data, philo) == 1 || check_if_dead(data, philo) == 1)
			break ;
	}
}
