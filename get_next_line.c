/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 07:45:38 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/28 22:22:50 by yorazaye         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <string.h>

static size_t	is_ch_th(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static size_t	bytes[2];
	char			tmp[BUFF_SIZE + 1];
	char			*ptr;

	bytes[1] = 0;
	while ((bytes[0] = read(fd, tmp, BUFF_SIZE)))
	{
		if (is_ch_th(tmp, '\n') != ft_strlen(tmp))
			bytes[1] += is_ch_th(tmp, '\n');
		else
			bytes[1] += bytes[0];
		ptr = (*line);
		(*line) = ft_strjoin(ptr, tmp);
		(*line)[bytes[1]] = '\0';
		ft_strclr(ptr);
		if (bytes[0] != is_ch_th(tmp, '\n'))
		{
			ft_strclr(tmp);
			break ;
		}
		ft_strclr(tmp);
	}
	ft_putstr(*line);
	return (bytes[0]);
}

#ifdef TEST

#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	int		rc;
	char	*r;

	i = 1;
	r = ft_strnew(1);
	if (ac >= 2)
	{
		fd = open(av[i], O_RDONLY);
		rc = get_next_line(fd, &r);
		ft_putchar('\n');
		rc = get_next_line(fd, &r);
		close(fd);
		//printf("%s\n", ft_strchr("Hello\nWorld", '\n'));
		//printf("%s\n", r);
	}
	return (0);
}

#endif
