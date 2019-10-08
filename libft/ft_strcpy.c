/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:32:32 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/21 19:52:23 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = -1;
	while (src[++i] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
