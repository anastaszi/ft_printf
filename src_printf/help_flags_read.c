/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_flags_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:32:10 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 13:25:41 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		read_flag(t_flag *rflag, const char *str, int *i, va_list ap)
{
	int len;

	len = 1;
	while (!ft_strchr(SPECIFS, str[*i + len]) && (str[*i + len] != '\0'))
	{
		if (ft_strchr(FLAGS, str[*i + len]))
			put_flag(rflag, str[*i + len]);
		else if (ft_isdigit(str[*i + len]))
			put_width(rflag, str, *i, &len);
		else if (str[*i + len] == '*')
			put_wc(rflag, str, *i, &len);
		else if (str[*i + len] == '.')
			put_pr(rflag);
		else if (str[*i + len] == '$')
			put_posix(rflag);
		else if (ft_strchr(LENGTHS, str[*i + len]))
			put_length(rflag, str + *i, &len, ap);
		else
			break ;
		len++;
	}
	rflag->specifier = str[*i + len];
	rflag->index = len;
	*i = ((str[*i + len] == '\0') ? ft_strlen((char*)str) : *i + 1 + len);
	return ((rflag->specifier == '\0') ? 0 : 1);
}

void	null_t_flag(t_flag *rflag)
{
	rflag->specifier = 0;
	rflag->flag_space = 0;
	rflag->flag_plus = 0;
	rflag->flag_minus = 0;
	rflag->flag_zero = 0;
	rflag->flag_hash = 0;
	rflag->width = 0;
	rflag->width_elem = 0;
	rflag->width_wc = 0;
	rflag->precision = 0;
	rflag->precision_num = 6;
	rflag->precision_wc = 0;
	rflag->posix = 0;
	rflag->posix_num = 0;
	rflag->length = NULL;
	rflag->tshort = 0;
	rflag->tlong = 0;
	rflag->tlonglong = 0;
	rflag->tintmax = 0;
	rflag->tint = 0;
	rflag->tchar = 0;
	rflag->tsizet = 0;
	rflag->bad = 0;
}

void	correct_flag(t_flag *rflag, va_list ap)
{
	if ((rflag->posix == 1) && (rflag->precision_wc == 1))
		rflag->precision_num = get_param_for_flag(ap, rflag->precision_wc_elem);
	if ((rflag->posix == 1) && (rflag->width_wc == 1))
		rflag->width = get_param_for_flag(ap, rflag->width_elem);
	if (!rflag->posix && (rflag->width_wc == 1 || rflag->precision_wc == 1))
		add_wc(ap, rflag);
	if (rflag->specifier == 'p')
		rflag->flag_hash = 1;
	if (rflag->flag_hash && !ft_strchr("oOxXpfFeE", rflag->specifier))
		rflag->flag_hash = 0;
	if ((rflag->flag_plus && rflag->flag_space) || (rflag->flag_space && \
		!ft_strchr("dDeEfFi", rflag->specifier)))
		rflag->flag_space = 0;
	if ((rflag->precision && rflag->precision_num && \
				ft_strchr("spSCc", rflag->specifier)) || \
			(rflag->flag_zero && rflag->flag_minus))
		rflag->flag_zero = 0;
	if ((rflag->precision && !rflag->precision_wc && ft_strchr("dDioOuixX", \
		rflag->specifier)) || (!rflag->precision_num && ft_strchr("fFeE", \
		rflag->specifier)))
		rflag->flag_zero = 0;
	if (rflag->flag_plus && !ft_strchr("dDeEfFi", rflag->specifier))
		rflag->flag_plus = 0;
	if (rflag->bad)
		rflag->specifier = 'd';
}
