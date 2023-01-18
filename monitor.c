/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:04:37 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/18 15:14:17 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_ate_time(t_data *data, t_philo *philo)
{
	if (philo->count_eat == data->must_eat && data->must_eat > 0)
		data->dinner_finish = 1;
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
