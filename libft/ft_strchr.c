/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:17:16 by mpimenta          #+#    #+#             */
/*   Updated: 2022/05/17 14:32:53 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	looking;

	looking = (char) c;
	str = (char *)s;
	while (*str != looking)
	{
		if (*str == '\0' && looking != '\0')
			return (NULL);
		str++;
	}
	return (str);
}
