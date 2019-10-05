/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:45:20 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/05 11:00:00 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

#include <stdio.h>

int		parse4nl(char *ptr, char **line)
{
	int		i;
	int		r;
	char	*tmp;

	i = 0;
	r = 0;
	tmp = ft_strchr(ptr, '\n') + 1;
	if (tmp != NULL)
	{
		while (ptr[i] != '\n')
			i++;
		*line = ft_strsub(ptr, 0, i);
		i = ft_strlen(tmp);
		ptr = ft_memmove(ptr, tmp, i);
		ft_strclr(tmp);
		r = 1;
	}
	else
		*line = ft_strdup(ptr);
	return (r);
}

int		get_next_line(int fd, char **line)
{
	char		tmp[BUFF_SIZE + 1];
	int			byte;
	static char	*ptr[FD_SIZE];

	if (!fd || !line)
		return (-1);
	if (ptr[fd])
		if (parse4nl(ptr[fd], line))
			return (1);
	while ((byte = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[byte] = '\0';
		if (parse4nl(tmp, line) == 1)
			break ;
	}
	ptr[fd] = ft_strdup(tmp);
	if (byte < 0)
		return (-1);
	if (byte != 0 || ptr[fd] || **line)
		return (1);
	return (0);
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("return is %d\n", get_next_line(fd, &line));
	printf("line is %s\n", line);
	printf("return is %d\n", get_next_line(fd, &line));
	printf("line is %s\n", line);
	return (0);
}
