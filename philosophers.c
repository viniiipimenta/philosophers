/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:53 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/23 15:34:54 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	set_philos(t_data *data, char **argv)
{
	int		i;
	long	last_ate;

	i = 0;
	data->num_philos = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	last_ate = get_time();
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->philo = malloc(sizeof(t_philo) * data->num_philos);
	while (i < data->num_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].count_eat = 0;
		data->philo[i].right_hand = i;
		data->philo[i].left_hand = (1 + i) % data->num_philos;
		data->philo[i].last_ate = last_ate;
		data->philo[i].data = data;
		i++;
	}
	create_forks(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (check_error(argv) == 1)
			return (0);
		if (argc == 6 && atoi(argv[5]) < 1)
		{
			printf("Invalid numbers of time to eat\n");
			return (0);
		}
		data.start_time = get_time();
		data.dead = 0;
		data.dinner_finish = 0;
		set_philos(&data, argv);
		init_threads(&data);
		destroy_forks(&data);
		free(data.philo);
	}
	else
		printf("Number of arguments invalid\n");
	return (0);
}
