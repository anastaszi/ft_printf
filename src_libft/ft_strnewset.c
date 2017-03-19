/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:22:44 by azimina           #+#    #+#             */
/*   Updated: 2017/03/06 23:22:51 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewset(size_t len, char c)
{
	char *temp;

	if (len > 0)
	{
		temp = ft_strnew(len);
		temp[len] = '\0';
		ft_memset((char *)temp, c, len);
		return (temp);
	}
	else
		return (0);
}