/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:04:37 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/18 16:35:56 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_ate_time(t_data *data, t_philo *philo)
{
	if (philo->count_eat == data->must_eat && data->must_eat > 0)
		data->dinner_finish = 1;
}

void	check_if_dead(t_data *data, t_philo *philo)
{
	if (data->die >= (get_time() - data->start_time) - philo->last_ate)
	{
		data->dead = 1;
		printf("%ldms %d Died\n", get_time() - data->start_time, philo->id);
	}
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
