/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:53 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/18 10:43:27 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	set_philos(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->num_philos = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]) * 1000;
	data->eat = ft_atoi(argv[3]) * 1000;
	data->sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
	{
		data->must_eat = ft_atoi(argv[5]);
	}
	else
		data->must_eat = 0;
	data->philo = malloc(sizeof(t_philo) * data->num_philos);
	while (i < data->num_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].count_eat = 0;
		data->philo[i].right_hand = i;
		data->philo[i].left_hand = (1 + i) % data->num_philos;
		data->philo[i].last_ate = 0;
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
			ft_putstr_fd("Invalid numbers of time to eat\n", 2);
			return (0);
		}
		data.if_die = 0;
		set_philos(&data, argv);
		init_threads(&data);
		destroy_forks(&data);
	}
	else
		ft_putstr_fd("Number of arguments invalid\n", 2);
	return (0);
}
