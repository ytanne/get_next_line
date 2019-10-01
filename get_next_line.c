/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 07:45:38 by yorazaye          #+#    #+#             */
/*   Updated: 2019/09/29 21:07:06 by yorazaye         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static size_t	str_upto_ch(char *str, char c)
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

int				get_next_line(int fd, char **line)
{
	int			byte;
	char		tmp[BUFF_SIZE + 1];
	static char	*chr[FD_SIZE];
	char		*ptr;

	while ((byte = read(fd, tmp, BUFF_SIZE)))
	{
		tmp[byte] = '\0';
		if (*line)
			ptr = *line;
		if (ft_strchr(tmp, '\n') != NULL)
		{
			ft_putstr(ft_strsub(tmp, 0, str_upto_ch(tmp, '\n')));
			ft_putstr("\nNew line is found\n");
			break ;
		}
		if (chr[fd] == NULL)
		{
			chr[fd] = tmp;
			ft_putstr("it was null, but not anymore\n");
		}	
		(*line) = ft_strjoin(ptr, tmp);
	}
	ft_putchar('\n');
	ft_putstr(*line);
	ft_putstr("---\n");
	return (0);
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
		fd = open(av[i++], O_RDONLY);
		rc = get_next_line(fd, &r);
		rc = get_next_line(fd, &r);
		close(fd);
		//printf("%s\n", ft_strchr("Hello\nWorld", '\n'));
	}
	return (0);
}

#endif
