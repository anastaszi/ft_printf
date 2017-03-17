/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:18:11 by azimina           #+#    #+#             */
/*   Updated: 2017/03/06 23:18:47 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char **str, char *add)
{
	char *new;
	
	new = NULL;
	new = ft_strnew(ft_strlen(*str) + ft_strlen(add));
	new = ft_strcpy(new, *str);
	if (add != NULL && new != NULL)
		new = ft_strcat(new, add);
	ft_memdel((void**)str);
	return (new);
}
