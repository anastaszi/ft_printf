/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlastelem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 19:35:33 by azimina           #+#    #+#             */
/*   Updated: 2016/12/29 19:35:37 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_lstlastelem(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		return (current->content);
	}
	return (NULL);
}
