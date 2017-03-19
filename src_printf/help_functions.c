/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:33:17 by azimina           #+#    #+#             */
/*   Updated: 2017/03/06 22:50:11 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define WR "\x1b[32mWARNING\x1b[0m: "
#define ER "\x1b[31mERROR\x1b[0m: "

int		strprint_del(char **str)
{
	int count;

	count = ft_strlen(*str);
	ft_putstr(*str);
	ft_memdel((void**)str);
	return (count);
}

int		rank(unsigned long long value, int base)
{
	if (value < (unsigned long long)base)
		return (1);
	return (1 + rank((value / base), base));
}

char	*str_to_char(int ch)
{
	char *str;

	str = (char *)malloc(2);
	str[0] = (char)ch;
	str[1] = '\0';
	return (str);
}

void	if_so_exit(char c)
{
	ft_putstr_fd(ER, 1);
	if (c == 'd')
		;//ft_putstr_fd("WRONG FLAG FORMAT\n", 2);
	else if (c == 'f')
		;//ft_putstr_fd("WRONG FLAG\n", 2);
	else if (c == 's')
		;//ft_putstr_fd("NO SPECIFIER FOR FLAG\n", 2);
	else if (c == 'z')
		;//ft_putstr_fd("BAD '0' flag\n", 2);
	else if (c == 'p')
		;//ft_putstr_fd("BAD POSIX FLAGS\n", 2);
	else if (c == 'n')
		;//ft_putstr_fd("BAD FLAG FOR 'n' SPECIFIER\n", 2);
	else if (c == 'm')
		;//ft_putstr_fd("'0' is ignored when '-' is present\n", 2);
	else if (c == 'c')
		;//ft_putstr_fd("Bad input for wint_t\n", 2);
	else
		;
	//exit(0);
}

void	if_so_warning(char c)
{
	ft_putstr_fd(WR, 1);
	if (c == 'p')
		ft_putstr_fd("'space' flag will be ignored\n", 2);
	else if (c == 'z')
		ft_putstr_fd("'0' flag will be ignored\n", 2);
	else if (c == 'h')
		ft_putstr_fd("bad '#' flag for this type of argument\n", 2);
	else if (c == 'n')
		ft_putstr_fd("bad length flag for specifier\n", 2);
	else if (c == 's')
		ft_putstr_fd("bad length flag for char/pointer argument\n", 2);
	else if (c == 'L')
		ft_putstr_fd("bad length flag for this type of argument\n", 2);
	else if (c == 'f')
		ft_putstr_fd("bad ' '/'+' flag for for this type of argument\n", 2);
	else
		ft_putstr_fd("You are awesome!\n", 2);
}
