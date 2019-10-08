/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:07:15 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/26 16:22:14 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree	*ft_btree_new_node(void *item)
{
	t_btree *new_tree;

	if (!item)
		return (NULL);
	new_tree = (t_btree *)malloc(sizeof(*new_tree));
	if (new_tree)
	{
		new_tree->item = item;
		new_tree->left = 0;
		new_tree->right = 0;
	}
	return (new_tree);
}
