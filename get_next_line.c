/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 07:45:38 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/27 10:47:32 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static size_t bytes;

int		get_next_line(int fd, char **line)
{
	bytes = read(fd, *line, BUFF_SIZE);
	return (bytes);
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
	if (ac >= 2)
	{
		r = (char *)malloc(sizeof(char) * 100);
		fd = open(av[i], O_RDONLY);
		rc = get_next_line(fd, &r);
		close(fd);
		printf("%s\n", r);
	}
	return (0);
}

#endif
