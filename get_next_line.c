/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awora <awora@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:01:34 by awora             #+#    #+#             */
/*   Updated: 2022/05/25 13:21:01 by awora            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_line(int fd, char *return_char)
{
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * 2);
	if (!buf)
		return (0);
	ret = 1;
	return_char = malloc(sizeof(char) * 2);
	while ((ret != 0 && !ft_strchr(return_char, '\n')))
	{
		ret = read(fd, buf, 1);
		buf[ret] = '\0';
		return_char = ft_strjoin(return_char, buf);
	}
	free(buf);
	if (ret == 0 && return_char[ret] == 0)
	{
		free(return_char);
		return (NULL);
	}
	return (return_char);
}

char	*get_next_line(int fd)
{
	static char	*return_char;

	if (read(fd, NULL, 0) == -1)
		return (NULL);
	return_char = get_read_line(fd, return_char);
	if (!return_char)
	{
		free (return_char);
		return (NULL);
	}
	return (return_char);
}
/*
int main()
{
    int fd;
    char *line;
    fd = open("42.txt", O_RDONLY);
    line  = get_next_line(fd);
    printf("%s", line);
	free(line);
    line  = get_next_line(fd);
	close(fd);
    printf("%s", line);
	free(line);
}*/

/* int main()
{
	int fd;
    char *line;
    fd = open("42.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
} */