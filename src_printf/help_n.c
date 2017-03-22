/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:33:21 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 13:44:08 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_n_char(int *j, signed char *ch)
{
	*ch = (signed char)*j;
}

static void	put_n_si(int *j, short int *ch)
{
	*ch = (short int)*j;
}

static void	put_n_i(int *j, int *ch)
{
	*ch = *j;
}

static void	get_n(int *j, va_list ap, t_flag rflag)
{
	if (rflag.tchar == 1)
		put_n_char(j, va_arg(ap, signed char*));
	else if (rflag.tshort == 1)
		put_n_si(j, va_arg(ap, short int*));
	else if (rflag.tintmax == 1)
		put_n_im(j, va_arg(ap, intmax_t*));
	else if ((rflag.tlong == 1) && (rflag.tsizet == 0))
		put_n_li(j, va_arg(ap, long int*));
	else if (rflag.tlonglong == 1)
		put_n_lli(j, va_arg(ap, long long int*));
	else if (rflag.tsizet == 1)
	{
		if (sizeof(size_t) == sizeof(long int))
			put_n_li(j, va_arg(ap, long int*));
		else
			put_n_i(j, va_arg(ap, int*));
	}
	else
		put_n_i(j, va_arg(ap, int*));
}

void		put_n_value(int *j, va_list ap, t_flag rflag)
{
	uintmax_t	temp;
	va_list		copy;
	int			num;

	if (rflag.posix == 1)
	{
		va_copy(copy, ap);
		num = rflag.posix_num;
		while (num-- > 1)
			temp = va_arg(copy, uintmax_t);
		get_n(j, copy, rflag);
		va_end(copy);
	}
	else
		get_n(j, ap, rflag);
}
