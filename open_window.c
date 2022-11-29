/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:52:45 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/29 16:47:50 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

mlx_t	*open_window(char *map, int i)
{
	mlx_t	*mlx;
	char	*buffer;
	int		x;
	int		y;
	int		fd;

	y = 0;
	fd = open(map, O_RDWR);
	buffer = get_next_line(fd);
	while (buffer != 0)
	{
		x = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		x = i;
		i = 0;
		y++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	mlx = mlx_init(x * 32, y * 32, "Finish the school", 1);
	return (mlx);
}
	