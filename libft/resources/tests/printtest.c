/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 10:41:45 by denden            #+#    #+#             */
/*   Updated: 2020/10/21 16:26:57 by denden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define BUFF_SIZE 10

int	read_line(const int fd, char **remaining_lines)
{
	char	buff[BUFF_SIZE + 1];
	int		read_value;
	char	*freeptr;

	while ((read_value = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_value] = 0;
		if (!*remaining_lines)
			*remaining_lines = ft_strdup(buff);
		else
		{
			freeptr = *remaining_lines;
			*remaining_lines = ft_strjoin(*remaining_lines, buff);
			ft_strdel(&freeptr);
		}
		if (!remaining_lines)
			return (0);
		if (ft_strchr(buff, '\n'))
			return (1);
	}
	if (read_value == -1)
		return (0);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*remaining_lines;
	char		*newline;
	char		*freeptr;
	size_t		len;

	if (!read_line(fd, &remaining_lines))
		return (-1);
	if (!remaining_lines)
		return (0);
	if ((newline = ft_strchr(remaining_lines, '\n')))
	{
		len = (size_t)(newline - remaining_lines);
		if (!(*line = ft_strsub(remaining_lines, 0, len)))
			return (-1);
		freeptr = remaining_lines;
		remaining_lines = ft_strsub(remaining_lines, len + 1, ft_strlen(remaining_lines) - len);
		ft_strdel(&freeptr);
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(remaining_lines)))
			return (-1);
		ft_strdel(&remaining_lines);
	}
	return (0);
}

int	main()
{
	char *line = NULL;
	char const *pathfile = "resources/tests/filetest";
	int fd = open(pathfile, O_CREAT | O_TRUNC | O_RDWR);
	int i = 0;
	char **strs = malloc(sizeof(*strs) * 5);

	if (fd == -1)
		printf("test ko : error open file\n");
	else
	{
		strs[0] = "il etait une fois 42";
		strs[1] = "y";
		strs[2] = "il etait une fois 42";
		strs[3] = "2147483647";
		strs[4] = 0;

		ft_putstr_fd("il etait une fois 42\n", fd);
		ft_putchar_fd('y', fd);
		ft_putchar_fd('\n', fd);
		ft_putendl_fd("il etait une fois 42", fd);
		ft_putnbr_fd(2147483647, fd);

		close(fd);
		fd = open(pathfile, O_RDONLY);

		while (i < 4)
		{
			get_next_line(fd, &line);
			if (ft_strequ(line, strs[i]))
				printf("test ok\n");
			else
				printf("test ko\n");
			i++;
			ft_strdel(&line);
		}
	}
	if (close(fd) == -1)
		printf("test ko : error close file\n");

	return (0);
}
