/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:53 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/10 13:42:37 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	check_error(char *str[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			check_num(&str[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
    if (ft_atoi(str[1]) < 1 || ft_atoi(str[1]) > 200)
    {
        ft_putstr_fd("Invalid numbers of philosophers\n", 2);
		exit(0);
    }
    i = 1;
    while (i < 5)
    {
        if (ft_atoi(str[i]) < 60)
        {
            ft_putstr_fd("Invalid numbers of time\n", 2);
		    exit(0);
        }
        i++;
    }
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		check_error(argv);
		if (argc  == 6 && atoi(argv[5]) < 1)
		{
			ft_putstr_fd("Invalid numbers of time to eat\n", 2);
		    exit(0);
		}

	}
	else
		ft_putstr_fd("Number of arguments invalid\n", 2);
	return (0);
}