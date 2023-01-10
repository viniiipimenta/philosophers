/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:14:41 by mpimenta          #+#    #+#             */
/*   Updated: 2022/11/17 14:49:57 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (str[i] - str2[i]);
	while ((i < n - 1)
		&& (str[i] == str2[i]) && (str[i] != '\0' || str2[i] != '\0'))
		i++;
	return (str[i] - str2[i]);
}
