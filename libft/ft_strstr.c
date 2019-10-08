/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:43:15 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/23 10:33:48 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		k = i;
		while (needle[j] == haystack[k] && needle[j] != '\0')
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + k - ft_strlen(needle)));
		i++;
	}
	if (*needle == '\0')
		return ((char *)haystack);
	return (NULL);
}
