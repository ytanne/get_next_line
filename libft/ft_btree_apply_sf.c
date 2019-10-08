/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_sf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:45:59 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/26 16:47:36 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_sf(t_btree *root, void (*f)(void *))
{
	if (root->left)
		ft_btree_apply_sf(root->left, f);
	if (root->right)
		ft_btree_apply_sf(root->right, f);
	if (root)
		f(root->item);
}
