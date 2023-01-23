/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:25:45 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/23 13:52:57 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msg(t_data *data, t_philo *philo, char way)
{
	if (check_ate_time(data, philo) == 0 && check_if_dead(data, philo) == 0)
	{
		pthread_mutex_lock(&(data->lock_print));
		if (way == 'f')
			printf("%ldms\t%d\thas taken a fork\n", (get_time()
					- data->start_time), philo->id);
		else if (way == 'e')
			printf("%ldms\t%d\tis eating\n", (get_time() - data->start_time),
				philo->id);
		else if (way == 's')
			printf("%ldms\t%d\tis sleeping\n", (get_time() - data->start_time),
				philo->id);
		else if (way == 't')
			printf("%ldms\t%d\tis thinking\n", (get_time() - data->start_time),
				philo->id);
		pthread_mutex_unlock(&(data->lock_print));
	}
}
