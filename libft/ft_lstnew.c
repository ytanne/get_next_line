/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 08:44:47 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/26 16:22:25 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n_list;

	if (!(n_list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		n_list->content = NULL;
		content_size = 0;
	}
	else
	{
		if (!(n_list->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(n_list->content, content, content_size);
	}
	n_list->content_size = content_size;
	n_list->next = NULL;
	return (n_list);
}
