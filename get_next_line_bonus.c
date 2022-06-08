/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awora <awora@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:01:01 by awora             #+#    #+#             */
/*   Updated: 2022/05/25 13:23:00 by awora            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*return_char[1024];

	if (read(fd, NULL, 0) == -1)
		return (NULL);
	return_char[fd] = get_read_line(fd, return_char[fd]);
	if (!return_char[fd])
	{
		free (return_char[fd]);
		return (NULL);
	}
	return (return_char[fd]);
}

/*int main()
{
    int fd;
    int fd1;
    char *line;
    fd = open("42.txt", O_RDONLY);
   // printf("%d\n", fd);
    fd1 = open("43.txt", O_RDONLY);
   // printf("%d\n", fd1);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
     line = get_next_line(fd1);
     close(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    close(fd);
    printf("%s", line);
    free(line);
    
}*/

/* int main()
{
	int fd;
	int fd1;
	char *line;
	int i = 0;
	int j = 0;
	fd = open("42.txt", O_RDONLY);
	open("43.txt", O_RDONLY);
	while(i < 2)
	{
		j = 0;
		while(j  < 3)
		{
			line = get_next_line(fd);
			printf("%s", line);
			j++;
		}
		printf("\n");
		fd++;
		i++;
	}
	
} */