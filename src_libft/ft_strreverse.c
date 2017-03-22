/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:36:42 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 12:09:43 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreverse(char **str)
{
	char	temp;
	int		i;
	int		len;

	len = ft_strlen(*str);
	i = 0;
	while (i < len / 2)
	{
		temp = (*str)[len - 1 - i];
		(*str)[len - 1 - i] = (*str)[i];
		(*str)[i++] = temp;
	}
}
