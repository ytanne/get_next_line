/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:45:20 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/03 12:29:36 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		init(char **line, char *tmp)
{
	int		i;
	char	*ptr[2];
	int		r;

	i = 0;
	r = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (i >= 0 && i < (int)ft_strlen(tmp))
		r = 1;
	ptr[0] = ft_strsub(tmp, 0, i);
	ptr[1] = *line;
	*line = ft_strjoin(ptr[1], ptr[0]);
	free(ptr[0]);
	if (*ptr[1])
		free(ptr[1]);
	return (r);
}

void	get_upto_nl(char *ptr, char **line)
{
	int		i;

	i = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (i == BUFF_SIZE)
		i = 0;
	*line = ft_strdup(ft_strchr(ptr, '\n') + 1);
}

int		get_next_line(const int fd, char **line)
{
	int			byte;
	char		tmp[BUFF_SIZE + 1];
	static char ptr[FD_SIZE][BUFF_SIZE + 1] = {[0 ... (FD_SIZE - 1)] = {0}};

	if (*line)
		ft_strclr(*line);
	if (*ptr[fd])
		get_upto_nl(ptr[fd], line);
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
	else if (byte < BUFF_SIZE)
		return (0);
	else
		return (1);
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("caesar_quote.txt", O_RDONLY);
	if (fd >= 0)
	{
		ft_putstr("Result of get_next_line is: ");
		ft_putnbr(get_next_line(fd, &line));
		ft_putchar('\n');
		ft_putstr("--------------------\n");
		ft_putstr(line);
		ft_putstr("\n--------------------\n");
		ft_putstr("Result of get_next_line is: ");
		ft_putnbr(get_next_line(fd, &line));
		ft_putchar('\n');
		ft_putstr("--------------------\n");
		ft_putstr(line);
	}
	else
		ft_putnbr(fd);
	return (0);
}
