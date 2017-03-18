/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:45:33 by azimina           #+#    #+#             */
/*   Updated: 2017/03/06 23:29:14 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPECIFS "sSpdDioOuUxXcCeEfFnaAgG"
# define FLAGS "-+ #0"
# define LENGTHS "lhLjz"
# define LETTERSMAX "0123456789ABCDEF"
# define LETTERSMIN "0123456789abcdef"
# define PRECISION 0.00000000000001
# define NOFLAGS "pSCDOU"
# define CHAR_MIN -128
# define CHAR_MAX 127
# define SHRT_MIN -32768
# define SHRT_MAX 32767
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define LONG_MIN -9223372036854775807
# define LONG_MAX 9223372036854775807
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <wchar.h>
# include <float.h>

typedef	struct		s_flag
{
	char			specifier;
	int				flag_space;
	int				flag_plus;
	int				flag_minus;
	int				flag_zero;
	int				flag_hash;
	int				width;
	int				width_wc;
	int				width_elem;
	int				precision;
	int				precision_num;
	int				precision_wc;
	int				precision_wc_elem;
	int				posix;
	int				posix_num;
	char			*length;
	int				index;
	int				tshort;
	int				tlong;
	int				tlonglong;
	int				tintmax;
	int				tint;
	int				tchar;
	int				tsizet;
}					t_flag;

typedef union       u_double_bits
{
    char            u[8];
    double         f;
}                   t_double_bits;
/*
** FT_PRINTF FUNCTIONS:
*/
int 				ft_printf(const char *restrict format, ...);
int					check_for_flag(const char *str);
/*
** FLAGS READ:
*/
void				check_valid_flag(t_flag rflag);
void				null_t_flag(t_flag *rflag);
void				read_flag(t_flag *rflag, const char *str, int i);
void				correct_flag(t_flag *rflag, va_list ap);
/*
** FLAGS FILL_1:
*/
void				add_wc(va_list ap, t_flag *rflag);
void				put_flag(t_flag *rflag, char c);
void				put_length(t_flag *rflag, const char *str, int i, int *len);
void				put_wc(t_flag *rflag, const char *str, int i, int *length);
void				put_width(t_flag *rflag, const char *str, int i, int *len);
/*
** FLAGS FILL_2:
*/
void				put_posix(t_flag *rflag, const char *str);
void				put_pr(t_flag *rflag);
void				put_flag_length(t_flag *rflag);
/*
** ARG_MANUP:
*/
void	arg_manip(t_flag rflag, va_list ap, int *j);
void add_chars(t_flag rflag, int *j, va_list ap);
/*
** STRING MANIPULATIONS:
*/
char				*getstr(t_flag rflag, va_list ap);
/*
** WIDE CHARS FUNCTIONS:
*/
char				*wint_tocharray(wint_t ch);
char				*wstr_tocharray(wchar_t *str);
/*
** COLORS MANIPULATIONS:
*/
void				add_char_or_color_to_str(int *j, const char *str, \
		int *index);
/*
** HELPING FUNCTIONS:
*/
int					strprint_del(char **str);
void				if_so_exit(char c);
void				if_so_warning(char c);
int					rank(unsigned long long value, int base);
char				*str_to_char(int ch);
/*
** POSIX FUNCTIONS:
*/
void				check_posix(const char *str);
int					get_param_for_flag(va_list ap, int i);
/*
** ITOA_BASE FUNCTIONS:
*/
char				*itoa_long_base(long long value, int base, \
		t_flag flag, char *str);
/*
** FLOAT_FUNCTIONS_1:
*/
void				double_to_char(double num, t_flag flag, int power, char **str);
void				double_to_science(double num, t_flag flag, int power, char **str);
/*
** FLOAT_FUNCTIONS_2:
*/
int					check_sign(double *num);
int					check_double(double num, char **str, t_flag flag);
int					before_after_dot(double num);
void				add_first(char **str, int i, t_flag flag);
/*
** BITS_FUNCTIONS:
*/
char				*str_to_hex(char *str);
char				*double_to_bitschar(double num);
#endif
