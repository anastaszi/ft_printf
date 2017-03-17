/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:52:47 by azimina           #+#    #+#             */
/*   Updated: 2016/12/13 19:54:28 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ws(char c)
{
	if ((c == ' ') || (c == '\n') || (c == '\t'))
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		begin;
	int		end;
	char	*new;

	begin = 0;
	if (s != NULL)
	{
		end = (int)ft_strlen(s);
		while (ws(s[begin]))
			begin++;
		if (begin == end)
			return (ft_strnew(0));
		while (ws(s[(end - 1)]))
			end--;
		if ((begin > 0) || (end < (int)ft_strlen(s)))
			new = ft_strsub(s, begin, end - begin);
		else
			new = ft_strdup(s);
		return (new);
	}
	return (NULL);
}
