/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:18:59 by azimina           #+#    #+#             */
/*   Updated: 2016/12/13 22:06:04 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **alst, void const *content, size_t content_size)
{
	t_list	*current;
	t_list	*new;

	current = *alst;
	if ((new = ft_lstnew(content, content_size)))
	{
		if (current == NULL)
			*alst = new;
		else
		{
			while (current->next != NULL)
				current = current->next;
			current->next = new;
		}
	}
}
