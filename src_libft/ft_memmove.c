/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:30:51 by azimina           #+#    #+#             */
/*   Updated: 2017/01/12 16:19:19 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *temp;

	temp = (unsigned char *)malloc(len + 1);
	if (temp)
	{
		ft_memcpy(temp, src, len);
		ft_memcpy(dst, temp, len);
	}
	free(temp);
	temp = NULL;
	return (dst);
}
