/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:18:05 by azimina           #+#    #+#             */
/*   Updated: 2016/12/13 21:18:14 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_head(t_list **alst, void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = ft_lstnew(content, content_size)))
	{
		if (alst != NULL)
			new->next = *alst;
		*alst = new;
	}
}
