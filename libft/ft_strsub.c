/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 09:14:13 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/21 14:32:06 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	r = ft_strnew(len);
	if (!r)
		return (NULL);
	while (++i < len)
		r[i] = s[start + i];
	r[i] = '\0';
	return (r);
}
