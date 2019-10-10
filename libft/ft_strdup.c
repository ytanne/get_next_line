/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:12:22 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/09 12:56:06 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*r;
	size_t	i;
	size_t	l;

	l = ft_strlen(s1);
	r = ft_strnew(l);
	if (!r)
		return (NULL);
	i = 0;
	while (i < l)
	{
		r[i] = s1[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
