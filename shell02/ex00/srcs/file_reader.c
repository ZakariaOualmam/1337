/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:39:21 by idouiri           #+#    #+#             */
/*   Updated: 2026/08/02 18:29:22 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_file_size(char *path)
{
	int		fd;
	int		bytes;
	int		total_bytes;
	char	buffer[1024];

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	total_bytes = 0;
	bytes = read(fd, buffer, 1024);
	while (bytes)
	{
		total_bytes += bytes;
		bytes = read(fd, buffer, 1024);
	}
	close(fd);
	return (total_bytes);
}

int	count_lines(char *buffer, int size)
{
	int	i;
	int	total_lines;

	i = 0;
	total_lines = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			total_lines++;
		i++;
	}
	return (total_lines);
}

void	read_file(char *path, char **buffer, int size)
{
	int	fd;
	int	bytes;

	fd = open(path, O_RDONLY);
	bytes = read(fd, *buffer, size);
	close(fd);
}
