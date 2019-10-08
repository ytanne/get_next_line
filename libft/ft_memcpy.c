/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:26:57 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/21 17:19:27 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*r;
	const char	*s;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	r = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		r[i] = s[i];
		i++;
	}
	return (dst);
}
