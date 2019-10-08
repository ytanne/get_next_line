/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 08:25:24 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/22 16:55:36 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ss;
	char	cc;

	i = 0;
	ss = (char *)s;
	cc = (char)c;
	while (ss[i] != '\0' && ss[i] != cc)
		i++;
	if (ss[i] == cc)
		return (ss + i);
	return (NULL);
}
