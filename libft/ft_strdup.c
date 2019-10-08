/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:12:22 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/19 14:21:12 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*r;
	size_t	i;

	r = ft_strnew(ft_strlen(s1));
	if (!r)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		r[i] = s1[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
