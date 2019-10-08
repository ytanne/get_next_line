/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 09:44:58 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/24 18:52:45 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;

	if (!s1 || !s2)
		return (NULL);
	r = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!r)
		return (NULL);
	ft_strcpy(r, s1);
	ft_strcat(r, s2);
	return (r);
}
