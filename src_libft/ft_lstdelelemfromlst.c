/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelelemfromlst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:22:16 by azimina           #+#    #+#             */
/*   Updated: 2017/01/23 14:22:41 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelelemfromlst(t_list **big, t_list *elem)
{
	t_list	*current;
	t_list	*new;

	current = *big;
	while ((current != NULL) && (*big != NULL))
	{
		if (current == elem)
		{
			if (current == *big)
				*big = current->next;
			else
				new->next = current->next;
			ft_lstdelone(&current, ft_del);
			break ;
		}
		new = current;
		current = current->next;
	}
}
