/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_n2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:41:34 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 12:25:14 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_n_lli(int *j, long long int *ch)
{
	*ch = *j;
}

void	put_n_im(int *j, intmax_t *ch)
{
	*ch = *j;
}

void	put_n_li(int *j, long int *ch)
{
	*ch = *j;
}
