/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:43:52 by azimina           #+#    #+#             */
/*   Updated: 2016/12/08 21:50:10 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_words(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		if ((*s != c) && ((!*(s - 1) || (*(s - 1) == c))))
			i++;
		s++;
	}
	return (i);
}

static int	word_size(char const *s, int i, char c)
{
	int		len;

	len = 0;
	while (s[i + len] != c)
	{
		if (s[i + len] == '\0')
			break ;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**array;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	words = num_words(s, c);
	if ((array = (char **)malloc((sizeof(char *) * (words + 1)))))
	{
		i = 0;
		j = 0;
		while ((s[i] != '\0') && (j < words))
		{
			while (s[i] == c)
				i++;
			array[j] = ft_strsub(s, i, word_size(s, i, c));
			i = i + word_size(s, i, c);
			j++;
		}
		array[j] = 0;
		return (array);
	}
	return (NULL);
}
