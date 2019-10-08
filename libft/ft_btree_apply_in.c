/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_in.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:38:59 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/26 16:43:48 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_in(t_btree *root, void (*f)(void*))
{
	if (root->left)
		ft_btree_apply_in(root->left, f);
	if (root)
		f(root->item);
	if (root->right)
		ft_btree_apply_in(root->right, f);
}
