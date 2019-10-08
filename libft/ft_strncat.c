/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:43:37 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/25 22:12:20 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	l[2];

	l[0] = ft_strlen(s1);
	l[1] = ft_strlen(s2);
	if (ft_strlen(s2) < n)
	{
		ft_strncpy(s1 + l[0], s2, l[1]);
		s1[l[0] + l[1]] = '\0';
	}
	else
	{
		ft_strncpy(s1 + l[0], s2, n);
		s1[l[0] + n] = '\0';
	}
	return (s1);
}
