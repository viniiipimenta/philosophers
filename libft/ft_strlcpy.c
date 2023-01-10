/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:43:54 by mpimenta          #+#    #+#             */
/*   Updated: 2022/05/20 12:07:47 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (ft_strlen(src) + 1 < dstsize)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	else if (dstsize > 0)
		ft_memcpy(dst, src, dstsize - 1);
	dst[dstsize - 1] = '\0';
	return (ft_strlen(src));
}
