/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:27:00 by mpimenta          #+#    #+#             */
/*   Updated: 2022/06/07 09:49:02 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*emptying(char **split, int j)
{
	while (j)
		free(split[j--]);
	free(split);
	return (0);
}

static int	word_count(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] != c && s[i] != '\0')
			i++;
		s = s + i;
		if (i)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count_words;
	int		i;
	int		j;

	i = 0;
	count_words = word_count((char *)s, c);
	split = malloc(sizeof(*split) * (count_words + 1));
	if (!split)
		return (0);
	while (i < count_words)
	{
		while (*(char *)s == c && *(char *)s != '\0')
			s++;
		j = 0;
		while (s[j] != c && s[j] != '\0')
			j++;
		split [i] = ft_substr(s, 0, j);
		if (!split[i++])
			emptying(split, i);
		s = s + j;
	}
	split[count_words] = NULL;
	return (split);
}
