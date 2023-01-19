/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:19:32 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/19 18:31:46 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	check_inputs(char *str[])
{
	int	i;

	if (ft_atoi(str[1]) < 1 || ft_atoi(str[1]) > 200)
	{
		printf("Invalid numbers of philosophers\n");
		return (1);
	}
	i = 1;
	while (++i < 5)
	{
		if (ft_atoi(str[i]) < 60)
		{
			printf("Invalid numbers of time\n");
			return (1);
		}
	}
	return (0);
}

int	check_error(char *str[])
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (str[++i])
	{
		while (str[i][++j])
		{
			if (check_num(&str[i][j]) == 1)
				return (1);
		}
		j = -1;
	}
	if (check_inputs(str) == 1)
		return (1);
	return (0);
}

int	check_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (ft_isdigit(num[i]) == 0)
		{
			printf("Input just positive numbers\n");
			return (1);
		}
		if ((num[i + 1] == '+' && (num[i] >= '0' && num[i] <= '9'))
			|| (num[i] == '+' && !num[i + 1]))
		{
			printf("Input just valid numbers\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_limit(long num)
{
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}
