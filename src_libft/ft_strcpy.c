/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:25:20 by azimina           #+#    #+#             */
/*   Updated: 2016/12/01 14:46:58 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *b;

	if (src != NULL)
	{
		b = dst;
		while (*src)
			*b++ = *src++;
		*b++ = '\0';
	}
	return (dst);
}
