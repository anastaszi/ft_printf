/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:17:39 by azimina           #+#    #+#             */
/*   Updated: 2016/12/08 17:40:38 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	char	*new;

	i = 0;
	if ((s1 != NULL) && (s2 != NULL))
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = ft_strnew(len);
		if (new != NULL)
		{
			ft_strcat(new, s1);
			ft_strcat(new, s2);
			new[len] = '\0';
			return (new);
		}
	}
	return (NULL);
}
