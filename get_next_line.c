/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:45:20 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/04 22:59:59 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

void	deal_with_ptr(char *ptr)
{
	char	*store;
	int		i;

	i = 0;
	store = ft_strchr(ptr, '\n') + 1;
	i = ft_strlen(store);
	ptr = ft_memmove(ptr, store, i);
	ptr[i] = '\0';
}

int		init(char **line, char *ptr)
{
	int		i;
	char	*tmp[2];

	i = 0;
	while (ptr[i] != '\n' && ptr[i] != '\0')
		i++;
	tmp[0] = ft_strsub(ptr, 0, i);
	tmp[1] = *line;
	*line = ft_strdup(tmp[0]);
	ft_memdel((void **)&tmp[0]);
	if (tmp[1])
		ft_memdel((void **)&tmp[1]);
	if (ptr[i] != '\n')
	{
		ptr[0] = '\0';
		return (0);
	}
	deal_with_ptr(ptr);
	return (1);
}

int		get_upto_nl(char *ptr, char **line)
{
	int		r;

	r = 0;
	if (init(line, ptr) == 1 || **line)
		r = 1;
	return (r);
}

int		get_next_line(const int fd, char **line)
{
	int			byte;
	char		tmp[BUFF_SIZE + 1];
	static char ptr[FD_SIZE][BUFF_SIZE + 1];

	if (*line)
		ft_strclr(*line);
	if (*ptr[fd])
		if (get_upto_nl(ptr[fd], line) == 1)
			return (1);
	while ((byte = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[byte] = '\0';
		if (init(line, tmp) == 1)
		{
			ft_strcpy(ptr[fd], tmp);
			break ;
		}
	}
	if (byte < 0)
		return (-1);
	else if (byte != 0 || *ptr[fd] || **line)
		return (1);
	else
		return (0);
}
