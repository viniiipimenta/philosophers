/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:32:28 by mpimenta          #+#    #+#             */
/*   Updated: 2022/06/03 09:37:55 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*s2;

	s2 = NULL;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] != '\0' && ft_strchr(set, s1[start]))
			start++;
		while (end > start && ft_strchr(set, s1[end - 1]))
			end--;
		s2 = malloc(sizeof(char) * (end - start + 1));
		if (!s2)
			return (s2);
		ft_strlcpy(s2, &s1[start], end - start + 1);
	}
	return (s2);
}
