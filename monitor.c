/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:04:37 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/18 13:24:41 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    check_ate_time(t_data *data, t_philo *philo)
{
    if (philo->count_eat == data->must_eat && data->must_eat > 0)
        data->dead = 1;
}