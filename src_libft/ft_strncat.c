/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:54:46 by azimina           #+#    #+#             */
/*   Updated: 2016/12/13 19:43:17 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*b;
	size_t	i;

	if (dst != NULL)
	{
		b = dst;
		i = ft_strlen(b);
		while ((*src) && (n-- != 0))
			b[i++] = *src++;
		b[i] = '\0';
	}
	return (dst);
}
