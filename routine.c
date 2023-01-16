/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:37:56 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/16 17:06:27 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void*    routine(void *d)
{
    t_philo *philo;

    philo = (t_philo *)d;
    printf("PHILO ID:%d\n", philo->id);
    printf("TIME TO DIE: %d\n", philo->data->die);
    return (0);
}

void    init_threads(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->num_philos)
        pthread_create(&(data->philo[i].thread_id), NULL, &routine, &(data->philo[i]));
    i = -1;
    while (++i < data->num_philos)
        pthread_join(data->philo[i].thread_id, NULL);
}