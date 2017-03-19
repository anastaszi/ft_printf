/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 12:24:50 by azimina           #+#    #+#             */
/*   Updated: 2017/03/02 12:42:26 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
}

void	read_flag(t_flag *rflag, const char *str, int i)
{
	int len;

	len = 1;
	while (!ft_strchr(SPECIFS, str[i + len]) && (str[i + len] != '\0'))
	{
		if (ft_strchr(FLAGS, str[i + len]))
			put_flag(rflag, str[i + len]);
		else if (ft_isdigit(str[i + len]))
			put_width(rflag, str, i, &len);
		else if (str[i + len] == '*')
			put_wc(rflag, str, i, &len);
		else if (str[i + len] == '.')
			put_pr(rflag);
		else if (str[i + len] == '$')
			put_posix(rflag, str);
		else if (ft_strchr(LENGTHS, str[i + len]))
			put_length(rflag, str, i, &len);
		else
				break;
		len++;
	}
	if (str[i + len] == '\0')
		if_so_exit('s');
	rflag->specifier = str[i + len];
	rflag->index = len;
}

void	check_not_null_l(t_flag rflag)
{
	if (ft_strchr("cs", rflag.specifier) && ft_strcmp(rflag.length, "l"))
		if_so_warning('s');
	if (ft_strchr(NOFLAGS, rflag.specifier))
		if_so_warning('n');
	if (ft_strchr("eEfF", rflag.specifier) && ft_strcmp(rflag.length, "l"))
		if_so_warning('n');
}

void	check_valid_flag(t_flag rflag)
{
	/*if (rflag.length != NULL)
		check_not_null_l(rflag);
	if (rflag.flag_hash && ft_strchr("dinuUDscSCp", rflag.specifier))
		if_so_warning('h');
	if (!ft_strchr("deEfFi", rflag.specifier) && (rflag.flag_space \
				|| rflag.flag_plus))
		if_so_warning('f');
	if (rflag.flag_zero && rflag.flag_minus)
		if_so_exit('m');
	if (rflag.flag_zero && ft_strchr("scSCp", rflag.specifier))
		if_so_exit('z');
	if (rflag.flag_plus && rflag.flag_space)
		if_so_warning('p');*/
	if (rflag.specifier == 'n' && rflag.index > 2)
		if_so_exit('n');
}

void	correct_flag(t_flag *rflag, va_list ap)
{
	if (rflag->flag_zero && rflag->flag_minus)
		rflag->flag_zero = 0;
	if (rflag->specifier == 'p')
		rflag->flag_hash = 1;
	if (rflag->flag_plus && rflag->flag_space)
		rflag->flag_space = 0;
	if (rflag->precision && rflag->precision_num && \
		ft_strchr("spSCc", rflag->specifier))
		rflag->flag_zero = 0;
	if (rflag->flag_hash && !ft_strchr("oOxXpfFeE", rflag->specifier))
		rflag->flag_hash = 0;
	if (rflag->flag_space && !ft_strchr("deEfFi", rflag->specifier))
		rflag->flag_space = 0;
	if (rflag->flag_plus && !ft_strchr("deEfFi", rflag->specifier))
		rflag->flag_plus = 0;
	if ((rflag->posix == 1) && (rflag->precision_wc == 1))
		rflag->precision_num = get_param_for_flag(ap, rflag->precision_wc_elem);
	if ((rflag->posix == 1) && (rflag->width_wc == 1))
		rflag->width = get_param_for_flag(ap, rflag->width_elem);
	if (rflag->precision && ft_strchr("diouixX", rflag->specifier))
		rflag->flag_zero = 0;
	if (!rflag->precision_num && ft_strchr("fFeE", rflag->specifier))
		rflag->flag_zero = 0;
	if (rflag->width < 0)
		{ 
			rflag->flag_minus = 1;
			rflag->width = -1 * rflag->width;
		}	
}
