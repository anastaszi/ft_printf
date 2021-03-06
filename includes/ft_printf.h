/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:37:46 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 12:22:15 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPECIFS "sSpdDioOuUxXcCeEfFnaAgG%"
# define ER "\x1b[31mERROR\x1b[0m: "
# define FLAGS "-+ #0"
# define LENGTHS "lhLjz"
# define LETTERSMAX "0123456789ABCDEF"
# define LETTERSMIN "0123456789abcdef"
# define NOFLAGS "pSCDOU"
# define PRECISION 0.00000000000001
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

typedef	struct	s_flag
{
	char		specifier;
	int			flag_space;
	int			flag_plus;
	int			flag_minus;
	int			flag_zero;
	int			flag_hash;
	int			width;
	int			width_wc;
	int			width_elem;
	int			precision;
	int			precision_num;
	int			precision_wc;
	int			precision_wc_elem;
	int			posix;
	int			posix_num;
	char		*length;
	int			index;
	int			tshort;
	int			tlong;
	int			tlonglong;
	int			tintmax;
	int			tint;
	int			tchar;
	int			tsizet;
	int			bad;
}				t_flag;

typedef union	u_double_bits
{
	char		u[8];
	double		f;
}				t_double_bits;

/*
** FT_PRINTF FUNCTIONS:
*/
int				ft_printf(const char *restrict format, ...);
/*
** FLAGS FUNCTIONS:
*/
void			add_flagged_params(int *j, int *i, va_list ap, \
		const char *format);
/*
** FLAGS READ:
*/
void			null_t_flag(t_flag *rflag);
int				read_flag(t_flag *rflag, const char *str, int *i, va_list ap);
void			correct_flag(t_flag *rflag, va_list ap);
/*
** FLAGS FILL_1:
*/
void			add_wc(va_list ap, t_flag *rflag);
void			put_flag(t_flag *rflag, char c);
void			put_length(t_flag *rflag, const char *str, int *len, \
		va_list ap);
void			put_wc(t_flag *rflag, const char *str, int i, int *length);
void			put_width(t_flag *rflag, const char *str, int i, int *len);
/*
** FLAGS FILL_2:
*/
void			put_posix(t_flag *rflag);
void			put_pr(t_flag *rflag);
void			put_flag_length(t_flag *rflag);
/*
** WIDTH_MANUP:
*/
void			add_bad_width(t_flag rflag, int *j);
char			*check_width(char **str, t_flag rflag);
/*
** CHARACTES AND STRING MANIPULATIONS:
*/
void			string_manip(t_flag rflag, va_list ap, char **str);
void			char_manip(va_list ap, char **str);
void			add_chars(t_flag rflag, int *j, va_list ap);
/*
** WIDE CHARS MANIPULATIONS:
*/
char			*wint_tocharray(wint_t ch);
char			*wstr_tocharray(wchar_t *str);
char			*wstrn_tocharray(wchar_t *str, int len);
/*
** NUMBERS MANIPULATIONS:
*/
void			check_precision_num(char **str, t_flag rflag);
char			*int_manip(va_list ap, t_flag rflag);
/*
** ITOA_BASE FUNCTIONS:
*/
char			*itoa_long_base(long long value, int base, \
		t_flag flag, char *str);
/*
** FLOAT MANIPULATIONS:
*/
void			double_manip(t_flag rflag, va_list ap, char **str);
void			add_precision_double(char **str, t_flag rflag);
/*
** FLOAT FUNCTIONS_1:
*/
void			double_to_char(double num, t_flag flag, int power, \
		char **str);
void			double_to_science(double num, t_flag flag, int power, \
		char **str);
/*
** FLOAT FUNCTIONS_2:
*/
int				check_sign(double *num);
int				check_double(double num, char **str, t_flag flag);
int				before_after_dot(double num);
void			add_first(char **str, int i, t_flag flag);
/*
** COLORS MANIPULATIONS:
*/
int				get_color(const char *str, int i, int *j);
/*
** POSIX FUNCTIONS:
*/
int				get_param_for_flag(va_list ap, int i);
/*
** HELPING FUNCTIONS:
*/
int				strprint_del(char **str);
int				rank(unsigned long long value, int base);
char			*str_to_char(int ch);
void			put_value(int *j, int *i);
void			good_number(long long int *temp, long long int max, \
		long long int min);
/*
** BITS_FUNCTIONS:
*/
char			*str_to_hex(char *str);
char			*double_to_bitschar(double num);
char			*str_to_bitschar(char *str_nt);
/*
** N_FLAG:
*/
void			put_n_value(int *j, va_list ap, t_flag flag);
void			put_n_lli(int *j, long long int *ch);
void			put_n_im(int *j, intmax_t *ch);
void			put_n_li(int *j, long int *ch);
#endif
