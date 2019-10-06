/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:45:20 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/05 19:06:38 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

#include <stdio.h>

/*
** Cating a string to the line
*/

void	dwl(char **line, char *str)
{
	char	*tmp;

	if (*line)
	{
		tmp = *line;
		*line = ft_strjoin(tmp, str);
		ft_strclr(tmp);
	}
	else
		*line = ft_strdup(str);
}

/*
** Function to search for new line 
*/

int		parse4nl(char *ptr, char **line)
{
	int		i;
	char	*tmp;
	char	*store;

	i = 0;
	tmp = ft_strchr(ptr, '\n');
	if (ft_strcmp(tmp, ""))
	{
		while (ptr[i] != '\n')
			i++;
		dwl(line, ft_strsub(ptr, 0, i));
		i = ft_strlen(tmp + 1);
		store = ft_strdup(tmp + 1);
		ft_strclr(ptr);
		ptr = store;
		return (1);
	}
	else
		dwl(line, ptr);
	return (0);
}

/*
** Adding static string to the line*
*/

int		get_next_line(int fd, char **line)
{
	char		tmp[BUFF_SIZE + 1];
	int			byte;
	static char	*ptr[FD_SIZE];

	if (!fd || !line)
		return (-1);
	*line = NULL;
	if (ptr[fd])
		if (parse4nl(ptr[fd], line) == 1)
			return (1);
	while ((byte = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[byte] = '\0';
		if (parse4nl(tmp, line) == 1)
		{
			ptr[fd] = ft_strdup(tmp);
			break ;
		}
	}
	if (byte < 0)
		return (-1);
	if (byte != 0)
		return (1);
	return (0);
}

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("caesar_quote.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
	}
	if (ret < 0)
		printf("Error happend\n");
	if (ret == 0)
		printf("End of file\n");
	return (0);
}
