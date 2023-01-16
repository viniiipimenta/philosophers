/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:53 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/16 14:59:57 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void set_philos(t_data *data, char **argv)
{
	int i;
	
	i = 0;
	data->num_philos = ft_atoi(argv[1]);
	// printf("NUMERO DE PHILOS: %d\n", data->num_philos);
	data->die = ft_atoi(argv[2]) * 1000;
	// printf("TIME TO DIE: %d\n", data->die);
	data->eat = ft_atoi(argv[3]) * 1000;
	// printf("TIME TO EAT: %d\n", data->eat);
	data->sleep = ft_atoi(argv[4]) * 1000;
	// printf("TIME TO SLEEP: %d\n", data->sleep);
	if (argv[5])
	{
		data->must_eat = ft_atoi(argv[5]);
		// printf("TIME MUST EAT: %d\n", data->must_eat);
	}
	else
		data->must_eat = 0;
	data->philo = malloc(sizeof(t_philo) * data->num_philos);
	while (i < data->num_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].count_eat = 0;
		data->philo[i].right_hand = i;
		data->philo[i].left_hand =  (1 + i) % data->num_philos;
		data->philo[i].last_ate = 0;
		i++;
	}
	// i = 0;
	// while (i < data->num_philos)
	// {
	// 	printf("--------------%d---------------\n", i);
	// 	printf("ID: %d\n", data->philo[i].id);
	// 	printf("COUNT EAT: %d\n", data->philo[i].count_eat);
	// 	printf("RIGHT_HAND: %d\n", data->philo[i].right_hand);
	// 	printf("LEFT_HAND: %d\n", data->philo[i].left_hand);
	// 	printf("LAST TIME ATE: %ld\n", data->philo[i].last_ate);
	// 	printf("------------------------------\n");
	// 	i++;
	// }
}

int	main(int argc, char *argv[])
{
	t_data data;

	if (argc == 5 || argc == 6)
	{
		if (check_error(argv) == 1)
			return (0);
		if (argc == 6 && atoi(argv[5]) < 1)
		{
			ft_putstr_fd("Invalid numbers of time to eat\n", 2);
			return (0);
		}
		set_philos(&data, argv);
	}
	else
		ft_putstr_fd("Number of arguments invalid\n", 2);
	return (0);
}
