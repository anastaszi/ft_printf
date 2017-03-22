/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_flags_fill2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:31:50 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 14:38:49 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_pr(t_flag *rflag)
{
	rflag->precision = 1;
	rflag->precision_num = 0;
}

void		put_posix(t_flag *rflag)
{
	if (!rflag->posix)
	{
		rflag->posix = 1;
		if (rflag->width != 0 && !rflag->width_wc)
		{
			rflag->posix_num = rflag->width;
			rflag->width = 0;
		}
		else if (rflag->width != 0 && rflag->width_wc)
		{
			rflag->width_elem = rflag->width;
			rflag->width = 0;
		}
		else
			;
	}
}

static void	put_for_other_specif(t_flag *rflag)
{
	if (ft_strchr("diouxX", rflag->specifier))
		if (!ft_strcmp(rflag->length, "hh"))
			rflag->tchar = 1;
		else if ((!ft_strcmp(rflag->length, "h")))
			rflag->tshort = 1;
		else if (!ft_strcmp(rflag->length, "l") ||\
			!ft_strcmp(rflag->length, "z") || !ft_strcmp(rflag->length, "j"))
			rflag->tlong = 1;
		else if ((!ft_strcmp(rflag->length, "ll")))
			rflag->tlonglong = 1;
		else if ((!ft_strcmp(rflag->length, "z")))
			rflag->tsizet = 1;
		else
			rflag->tintmax = 1;
	else
		;
}

void		put_flag_length(t_flag *rflag)
{
	if (rflag->length == NULL)
		if (ft_strchr("diouxX", rflag->specifier))
			rflag->tint = 1;
		else if (ft_strchr("DOUp", rflag->specifier))
			rflag->tlong = 1;
		else
			;
	else
		put_for_other_specif(rflag);
}
