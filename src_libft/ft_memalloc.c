/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:41:18 by azimina           #+#    #+#             */
/*   Updated: 2016/12/05 18:52:31 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memalloc;

	if ((memalloc = (void *)malloc(size)))
	{
		ft_memset(memalloc, 0, size);
		return (memalloc);
	}
	return (NULL);
}
