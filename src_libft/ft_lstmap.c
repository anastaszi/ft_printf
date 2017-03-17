/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:44:18 by azimina           #+#    #+#             */
/*   Updated: 2016/12/13 16:59:10 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*current;

	new = NULL;
	current = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	if ((new = (*f)(ft_lstnew(lst->content, lst->content_size))))
	{
		current = new;
		lst = lst->next;
		while (lst != NULL)
		{
			current->next = (*f)(ft_lstnew(lst->content, lst->content_size));
			current = current->next;
			lst = lst->next;
		}
	}
	return (new);
}
