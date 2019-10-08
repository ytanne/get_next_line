/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:36:02 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/25 08:26:11 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_cw(char const *s, char c)
{
	size_t	i;
	int		fl;
	int		len;

	i = 0;
	fl = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && fl == 0)
		{
			fl = 1;
			len++;
		}
		else if (s[i] == c)
			fl = 0;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		fl;
	size_t	i[3];

	fl = 0;
	i[0] = 0;
	i[2] = -1;
	if (!s || !c)
		return (NULL);
	if (!(r = (char **)malloc(sizeof(char *) * (ft_cw(s, c) + 1))))
		return (NULL);
	while (++i[2] < ft_cw(s, c))
	{
		while (s[i[0]] == c && s[i[0]] != '\0')
			i[0]++;
		i[1] = i[0];
		while (s[i[1]] != c && s[i[1]] != '\0')
			i[1]++;
		r[i[2]] = ft_strsub(s, i[0], i[1] - i[0]);
		i[0] = i[1];
	}
	r[i[2]] = (NULL);
	return (r);
}
