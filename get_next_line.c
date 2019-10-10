/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:45:20 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/09 23:53:56 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

void	line_maker(char **dest, char **src)
{
	char	*ptr;

	if (!(*dest))
		*dest = ft_strdup(*src);
	else
	{
		ptr = *dest;
		*dest = ft_strjoin(*dest, *src);
		ft_strdel(&ptr);
	}
	ft_strdel(src);
}

int		init(char **line, char **str)
{
	int		i;
	char	*tmp;
	int		r;

	i = 0;
	r = 0;
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{
		tmp = ft_strsub(*str, 0, i);
		line_maker(line, &tmp);
		tmp = ft_strdup(*str + i + 1);
		ft_strdel(str);
		*str = tmp;
		if (*str[0] == '\0')
			ft_strdel(str);
		r = 1;
	}
	else
		line_maker(line, str);
	return (r);
}

int		need_to_decide(char *str, int byte, char **line)
{
	if (byte < 0)
		return (-1);
	else if (byte == 0 && !str && !(*line))
		return (0);
	else
		return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*tmp;
	int			byte;
	static char	*heap[FD_SIZE];

	tmp = NULL;
	if ((fd < 0 || line == NULL) || (read(fd, tmp, 0) < 0))
		return (-1);
	*line = NULL;
	if (heap[fd])
		if (init(line, &heap[fd]) == 1)
			return (1);
	while ((tmp = ft_strnew(BUFF_SIZE)) &&
				((byte = read(fd, tmp, BUFF_SIZE)) > 0))
	{
		tmp[byte] = '\0';
		line_maker(&heap[fd], &tmp);
		if (init(line, &heap[fd]) == 1)
			break ;
	}
	return (need_to_decide(heap[fd], byte, line));
}
