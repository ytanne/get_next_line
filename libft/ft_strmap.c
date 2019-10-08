/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:55:29 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/23 12:33:20 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	size_t	i;

	i = -1;
	if (!s || !f)
		return (NULL);
	if (!(s1 = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		s1[i] = f(s[i]);
	return (s1);
}
