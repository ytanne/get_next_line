/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:48:01 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/22 16:52:45 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*sc;

	sc = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*sc == (unsigned char)c)
			return ((void *)sc);
		sc++;
	}
	return (NULL);
}
