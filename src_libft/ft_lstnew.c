/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:52:20 by azimina           #+#    #+#             */
/*   Updated: 2016/12/13 19:53:02 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ne;

	if ((ne = (t_list*)malloc(sizeof(t_list))))
	{
		if ((ne->content = ft_memalloc(content_size)))
		{
			if (content != NULL)
			{
				ne->content = ft_memcpy(ne->content, content, content_size);
				ne->content_size = content_size;
			}
			else
			{
				ne->content = NULL;
				ne->content_size = 0;
			}
			ne->next = NULL;
			return (ne);
		}
	}
	return (NULL);
}
