/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:15:10 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/26 17:13:33 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned int	r;
	unsigned char	*sc1;
	unsigned char	*sc2;

	i = 0;
	r = 0;
	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	while (i < n && (sc1[i] || sc2[i]))
	{
		r = sc1[i] - sc2[i];
		if (r != 0)
			return ((int)r);
		i++;
	}
	return (r);
}
