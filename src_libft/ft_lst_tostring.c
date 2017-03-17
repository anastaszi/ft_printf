/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tostring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:50:21 by azimina           #+#    #+#             */
/*   Updated: 2017/01/17 14:17:25 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_tostring(t_list **lst)
{
	t_list	*current;
	size_t	count;
	char	*str;

	current = *lst;
	count = 0;
	if (*lst == NULL || lst == NULL)
		return (NULL);
	while (current != NULL)
	{
		count = count + current->content_size;
		current = current->next;
	}
	str = (char *)ft_memalloc(count + 1);
	current = *lst;
	while (current != NULL)
	{
		str = ft_strncat(str, (char *)current->content, current->content_size);
		current = current->next;
	}
	ft_lsttotaldel(lst);
	return (str);
}
