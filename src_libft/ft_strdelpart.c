/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelpart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:36:22 by azimina           #+#    #+#             */
/*   Updated: 2017/03/20 15:46:41 by zmichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdelpart(char **str, size_t start)
{
	char *temp;

	temp = *str;
	if (temp != NULL && start < ft_strlen(temp))
	{
		while (temp[start] != '\0')
		{
			temp[start] = '\0';
			start++;
		}
	}
}
