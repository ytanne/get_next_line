/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:51:39 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/26 16:57:32 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int		bits;

	if (!octet)
		return ;
	bits = 256;
	while (bits >>= 1)
		(bits & octet) ? (ft_putchar('1')) : (ft_putchar('1'));
}
