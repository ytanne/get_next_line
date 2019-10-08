/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:23:21 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/23 12:33:42 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	size_t	i;

	i = -1;
	if (!s || !f)
		return (NULL);
	if (!(s1 = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		s1[i] = f(i, s[i]);
	return (s1);
}
