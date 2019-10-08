/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_pr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:38:03 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/26 16:38:04 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_pr(t_btree *root, void (*f)(void *))
{
	if (root)
	{
		f(root->item);
		ft_btree_apply_pr(root->left, f);
		ft_btree_apply_pr(root->right, f);
	}
}
