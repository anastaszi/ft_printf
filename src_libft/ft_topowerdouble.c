/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_topowerdouble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:37:10 by azimina           #+#    #+#             */
/*   Updated: 2017/03/20 15:37:11 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_topowerdouble(double num, int i)
{
	if (num == 0)
		return (0);
	if (i == 0)
		return (1);
	if (i < 0)
		return (ft_topowerdouble(num, i + 1) / num);
	return (num * ft_topowerdouble(num, i - 1));
}
