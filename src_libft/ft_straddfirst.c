/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:19:15 by azimina           #+#    #+#             */
/*   Updated: 2017/03/06 23:19:24 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddfirst(char **str, char *add)
{
	char *new;

	new = ft_strnew(ft_strlen(*str) + ft_strlen(add));
	new = ft_strcpy(new, add);
	if (*str != NULL)
	{
		new = ft_strcat(new, *str);
		ft_memdel((void**)str);
	}
	return (new);
}
