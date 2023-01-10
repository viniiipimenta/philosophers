/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:53 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/10 16:16:21 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		if (check_error(argv) == 1)
			return (0);
		if (argc == 6 && atoi(argv[5]) < 1)
		{
			ft_putstr_fd("Invalid numbers of time to eat\n", 2);
			return (0);
		}
	}
	else
		ft_putstr_fd("Number of arguments invalid\n", 2);
	return (0);
}
