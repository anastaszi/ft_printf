/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chararraylen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:19:50 by azimina           #+#    #+#             */
/*   Updated: 2017/01/23 14:20:52 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_chararraylen(const char **array)
{
	size_t len;

	len = 0;
	while (array[len] != 0)
		len++;
	return (len);
}
