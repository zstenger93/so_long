/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:19:44 by zstenger          #+#    #+#             */
/*   Updated: 2022/12/11 20:38:58 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_t	*ft_open_mapsize_window(char *map, int count)
{
	mlx_t	*mlx;
	int		x;
	int		y;
	int		fd;
	char	*buffer;

	fd = open(map, O_RDWR);
	buffer = get_next_line(fd);
	y = 0;
	while (buffer != 0)
	{
		x = 0;
		while (buffer[count] != '\n' && buffer[count] != '\0')
			count++;
		x = count;
		count = 0;
		y++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	mlx = mlx_init(x * 32, y * 32, "Survive The NORM", 1);
	return (mlx);
}

void	ft_make_new_images(mlx_t *mlx, t_image *img)
{
	img->walking_path = mlx_new_image(mlx, 32, 32);
	img->player = mlx_new_image(mlx, 32, 32);
	img->wall = mlx_new_image(mlx, 32, 32);
	img->pickitup = mlx_new_image(mlx, 32, 32);
	img->exit = mlx_new_image(mlx, 32, 32);
	img->enemy = mlx_new_image(mlx, 32, 32);
	img->enemy2 = mlx_new_image(mlx, 32, 32);
	img->enemy3 = mlx_new_image(mlx, 32, 32);
	img->move = mlx_new_image(mlx, 32, 32);
}

void	ft_make_map(mlx_t *mlx, char *map)
{
	int		x;
	int		y;
	int		fd;
	int		count;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		count = 0;
		x = 0;
		while (line[count] != '\n' && line[count] != '\0')
		{
			ft_put_loaded_image(mlx, line[count], x, y);
			x += 32;
			count++;
		}
		free(line);
		line = get_next_line(fd);
		y += 32;
	}
	close(fd);
}

void	ft_put_loaded_image(mlx_t *mlx, char c, int x, int y)
{
	if (c == 'F' || c == 'E' || c == '0' || c == 'P' || c == 'C' || c == 'N'
		|| c == 'B')
		ft_load_walking_path(mlx, x, y);
	if (c == '1')
		ft_load_wall(mlx, x, y);
	if (c == 'C')
		ft_load_pickitup(mlx, x, y, 'H');
	if (c == 'E')
		ft_load_exit(mlx, x, y, 'J');
	if (c == 'F')
		ft_load_enemy(mlx, x, y, 'T');
	if (c == 'N')
		ft_l_e2(mlx, x, y, 'K');
	if (c == 'B')
		ft_l_e3(mlx, x, y, 'Z');
	if (c == 'P')
		ft_load_player(mlx, x, y, 'X');
}

char	ft_last_line(char *line, char *lineb, size_t *length, size_t count)
{
	count = 0;
	if (line == NULL)
	{
		while (count < *length)
		{
			if (lineb[count++] != '1')
				return ('1');
		}
	}
	free(line);
	free(lineb);
	return (0);
}
