/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:17:41 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/23 10:25:55 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	char	*sc;
	char	cc;

	sc = (char *)s;
	cc = (char)c;
	r = NULL;
	while (*sc)
	{
		if (*(sc) == cc)
			r = sc;
		sc++;
	}
	if (*sc == cc)
		r = sc;
	return (r);
}
