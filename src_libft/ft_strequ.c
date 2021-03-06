/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:03:20 by azimina           #+#    #+#             */
/*   Updated: 2016/12/08 16:17:19 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if ((s1 != NULL) && (s2 != NULL))
	{
		while (*s1)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
		if (*s2 != '\0')
			return (0);
		else
			return (1);
	}
	return (0);
}
