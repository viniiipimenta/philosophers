/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:54:08 by mpimenta          #+#    #+#             */
/*   Updated: 2022/05/20 09:22:52 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	j;
	char	*str;

	j = (char)c;
	str = NULL;
	while (*s != '\0')
	{
		if (*s == j)
			str = (char *)s;
		s++;
	}
	if (c == '\0')
		str = (char *)s;
	return (str);
}
