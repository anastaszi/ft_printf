/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:20:30 by azimina           #+#    #+#             */
/*   Updated: 2017/03/06 23:21:21 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnadd(char **str, const char *add, size_t len)
{
	char *new;

	new = ft_strnew(ft_strlen(*str) + len);
	new = ft_strcpy(new, *str);
	new = ft_strncat(new, add, len);
	ft_memdel((void**)str);
	return (new);
}
