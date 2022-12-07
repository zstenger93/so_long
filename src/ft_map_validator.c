/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:59:37 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/07 23:03:19 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	ft_map_validator(char *argv)
{
	size_t	length;
	size_t	row;
	char	error;

	row = 0;
	error = ft_map_have_walls(open(argv, O_RDWR), &length, &row, 0);
	if (error != 0)
		return (error);
	error = ft_map_have_all_elements(open(argv, O_RDWR), 0, 0, 0, 0, 0);
	if (error != 0)
		return (error);
	error = ft_map_with_validpath(argv, row, length, 0);
	if (error != 0)
		return (error);
	return (0);
}

char	ft_map_have_walls(int fd, size_t *length, size_t *row, size_t count)
{
	char	*line;
	char	*lineb;

	line = get_next_line(fd);
	*length = ft_gnlinelen(line);
	lineb = malloc((*length + 1));
	if (lineb == NULL)
		return ('A');
	while (line)
	{
		if (*length != ft_gnlinelen(line))
			return ('R');
		if (line[0] != '1' || line[*length - 1] != '1')
			return ('1');
		ft_strlcpy(lineb, line, *length + 1);
		free(line);
		line = get_next_line(fd);
		count = 0;
		if ((*row)++ == 0)
		{
			while (count < *length)
			{
				if (lineb[count++] != '1')
					return ('1');
			}
		}
	}
	if (line == NULL)
	{
		count = 0;
		while (count < *length)
		{
			if (lineb[count++] != '1')
				return ('1');
		}
	}
	free(lineb);
	return (0);
}

char	ft_map_have_all_elements(int fd, char ext, char pick, char plyr, char n, char f)
{
	size_t	length;
	size_t	count;
	char	*line;
	char	linecopy;

	line = get_next_line(fd);
	length = ft_gnlinelen(line);
	while (line)
	{
		count = 0;
		while (count < length)
		{
			linecopy = line[count++];
			if (ft_map_element_check(linecopy, &plyr, &pick, &ext, &n, &f) == 'I')
				return ('I');
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!plyr || !ext || plyr > 1 || ext > 1)
		return ('O');
	else if ((plyr + ext + pick) != 3)
		return ('M');
	if (!f || !n || f > 1 || n > 1)
		return ('L');
	return (0);
}

char	ft_map_element_check(char c, char *plyr, char *pick, char *ext, char *n, char *f)
{
	if (c == 'C')
		*pick = 1;
	else if (c == 'E')
		(*ext)++;
	else if (c == 'P')
		(*plyr)++;
	else if (c == 'N')
		(*n)++;
	else if (c == 'F')
		(*f)++;
	else if (c != '1' && c != '0' && c != '\n')
		return ('I');
	return (0);
}

char	ft_map_with_validpath(char *argv, size_t rows, size_t columns, int fd)
{
	size_t	x;
	size_t	y;
	size_t	path;
	char	**map;
	char	*line;

	fd = open(argv, O_RDONLY);
	map = malloc(rows * sizeof(char *));
	if (map == NULL)
		return ('A');
	line = get_next_line(fd);
	path = 0;
	while (line != NULL)
	{
		map[path] = malloc((columns + 1));
		if (map[path] == NULL)
			return ('A');
		ft_strlcpy(map[path++], line, columns +1);
		free(line);
		line = get_next_line(fd);
	}
	ft_get_player(map, &x, &y, columns);
	path = ft_dfs(map, x, y, rows);
	ft_free_map(map, rows);
	return (path);
}
