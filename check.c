/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:19:32 by mpimenta          #+#    #+#             */
/*   Updated: 2023/01/10 16:02:43 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	check_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (ft_isdigit(num[i]) == 0)
		{
			ft_putstr_fd("Input just positive numbers\n", 2);
			return (1);
		}
		if ((num[i + 1] == '+' && (num[i] >= '0' && num[i] <= '9'))
			|| (num[i] == '+' && !num[i + 1]))
		{
			ft_putstr_fd("Input just valid numbers\n", 2);
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
